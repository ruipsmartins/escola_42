#include "BitcoinExchange.hpp"
#include <cstddef>
#include <cstdlib>
#include <exception>
#include <fstream>
#include <iostream>
#include <istream>
#include <ostream>
#include <sstream>
#include <stdexcept>
#include <string>

// _________________ Constructor.

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &_src) { *this = _src; }
BitcoinExchange::~BitcoinExchange() {}

//___________________ Overload Operator.
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &_src) {
  if (this != &_src) {
    _bitcoinData = _src._bitcoinData;
  }
  return (*this);
}

//___________________ Member Functions.

void BitcoinExchange::readBitcoinFile(const std::string &fileName) {
  std::ifstream bitFile(fileName.c_str());
  float value;
  std::string date;

  if (!bitFile.is_open())
    throw(std::runtime_error("🚫 Error: Could not open the file 🚫"));
  std::cout << GREEN << "✅ File Open and ready ✅" << RESET << std::endl;
  std::string line;
  while (std::getline(bitFile, line)) {
    std::istringstream iss(line);
    size_t position = line.find(',');
    if (position != std::string::npos) {
      date = line.substr(0, position);
      iss.str(line.substr(position + 1));
      iss >> value;
    }
    _bitcoinData[date] = value;
  }
  bitFile.close();
}

bool checker(const float &value) {
  if (value < 0) {
    std::cout << BLUE << "🔵 Error: value is not a positive number 🔵" << RESET
              << std::endl;
    return (false);
  }
  if (value > 1000) {
    std::cout << MAGENTA << "🔺 Error: value exceeds the maximum allowed 🔺"
              << RESET << std::endl;
    return (false);
  }
  return (true);
}
bool isValidDate(const std::string &date) {
  int year, month, day;
  if (date.size() != 11 || date[4] != '-' || date[7] != '-') {
    return (false);
  }
  year = std::atoi(date.substr(0, 4).c_str());
  month = std::atoi(date.substr(5, 2).c_str());
  day = std::atoi(date.substr(8, 2).c_str());

  if (year < 2000 || month < 1 || month > 12 || day < 1 || day > 31) {
    return (false);
  }
  return (true);
}

void BitcoinExchange::readSearchingFile(const std::string &fileQuery) {
  std::ifstream query(fileQuery.c_str());
  if (!query.is_open())
    throw std::runtime_error("Error: Could not open the file");

  std::string line;
  std::string date;
  std::getline(query, line);
  while (std::getline(query, line)) {
    std::istringstream iss(line);
    size_t position = line.find('|');
    if (position != std::string::npos) {
      date = line.substr(0, position);
      if (!isValidDate(date)) {
        std::cout << YELLOW << "-Error: bad input => " << date << RESET
                  << std::endl;
        continue;
      }
      iss.str(line.substr(position + 1));
      float value;
      if (!(iss >> value)) {
        std::cout << RED << "ERROR: Invalid value for date " << RESET << date
                  << std::endl;
        continue;
      } else if (!checker(value))
        continue;
      try {
        float bitcoinPrice = getPrice(date);
        // std::cout << GREEN <<  "// ______________ ORIGINAL DATA DATABASE
        // ______________" << RESET << std::endl; std::cout << date << " => " <<
        // bitcoinPrice
        //           << std::endl;
        // std::cout << YELLOW <<  "//
        // ____________________MULTIPLICATION__________________" << RESET <<
        // std::endl;d
        std::cout << date << " => " << value << " = " << value * bitcoinPrice
                  << std::endl;
      } catch (std::exception &e) {
        std::cout << RED << e.what() << RESET << std::endl;
      }

    } else {
      // Handle lines with no delimiter
      std::ostringstream oss;
      std::cout << RED << "ERROR: Missing delimiter in line: " << RED << line
                << std::endl;
    }
  }
  query.close();
}

float BitcoinExchange::getPrice(const std::string &_date) {
  std::map<std::string, float>::const_iterator it = _bitcoinData.find(_date);
  if (it != _bitcoinData.end())
    return it->second;

  // If the exact date is not found, find the closest previous date
  it = _bitcoinData.lower_bound(_date);
  if (it == _bitcoinData.begin()) {
    throw(
        std::runtime_error("Error not data find and not lower data available"));
  }
  if (it != _bitcoinData.begin() || it->first != _date) {
    --it;
    return it->second;
  }
  return 0;
}

std::map<std::string, float> BitcoinExchange::getBitcoinData() {
  return (_bitcoinData);
}