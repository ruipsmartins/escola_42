#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <iomanip>

class ScalarConverter{
	
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &copy);
	public:
		static void convert(const std::string &value);
};

int findType(const std::string &value);
void specialCases(const std::string &value);
void printInt(const std::string &value);
void printFloat(const std::string &value);
void printDouble(const std::string &value);
void printChar(char c);

#endif