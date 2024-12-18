#include "BitcoinExchange.hpp"

int main(int arg, char *argv[]) {
  // 1. Check the number of arguments.
  if (arg == 1)
    return 1;
  try {

    // Creation of the bitcoin Class.
    BitcoinExchange bitConvert;
    bitConvert.readBitcoinFile("data.csv");

    // 2. Check the open file function.
    std::cout << GREEN << "// ______________ SEARCH FILE ______________"
              << RESET << std::endl;
    std::ifstream file1(argv[1]);
    std::string line1;
    while (std::getline(file1, line1))
      std::cout << line1 << std::endl;

    std::cout << GREEN << "// ______________ After Output File ______________"
              << RESET << std::endl;
    bitConvert.readSearchingFile(argv[1]);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}