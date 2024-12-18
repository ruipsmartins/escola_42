#include "PmergeMe.hpp"
#include <exception>

template <typename T> void print(const T &container) {
  std::cout << "[";
  for (typename T::const_iterator it = container.begin(); it != container.end();
       ++it) {
    typename T::const_iterator itCheck = it;
    std::cout << *it;
    if (++itCheck != container.end())
      std::cout << ",";
  }
  std::cout << "]" << std::endl;
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cout << "Not enought args" << std::endl;
    return (1);
  }

  PmergeMe sorting;
  try {

    for (int i = 1; i < argc; i++)
      sorting.inputCheck(argv[i]);

    std::cout << YELLOW << "BEFORE : ";
    print(sorting.getList());

    sorting.runTimeManager();

  } catch (std::exception &e) {
    std::cout << RED << e.what() << RESET << std::endl;
  }
}

