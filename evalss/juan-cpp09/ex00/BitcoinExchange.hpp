#pragma once

#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <stdexcept>
#include <string>
#include <algorithm>

// ANSI color codes
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

class BitcoinExchange {
public:
  //_______ Constructor.
  BitcoinExchange();
  BitcoinExchange(const BitcoinExchange &_src);

  //_______ Overload Operator.
  BitcoinExchange &operator=(const BitcoinExchange &_src);

  //_______ Destructor.
  ~BitcoinExchange();

  //_______ Member Functions.

  //_______ Read Files
  void readBitcoinFile(const std::string &fileName);
  void readSearchingFile(const std::string &fileQuery);
  float getPrice(const std::string &_date);

  //_______ Search Value
  void searchValue();
  void createOutputFile(const std::string &fileName,
                        const std::map<std::string, float> &data);

  //_______ Getters
  std::map<std::string, float> getBitcoinData();

private:
  std::map<std::string, float> _bitcoinData;
};
