#ifndef CONVERSION_HPP
#define CONVERSION_HPP

#include <iostream>
#include <limits>
#include <limits.h>
#include <stdlib.h>

#define ERROR 0
#define INT 1
#define DOUBLE 2
#define CHAR 3
#define FLOAT 4
#define NAN_INF 5

class ScalarConverter {
	private:
		int _type;
		std::string _input;
		int _int;
		double _double;
		float _float;
		char _char;
	protected:
		
	public:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter& copy);
		ScalarConverter& operator=(const ScalarConverter& copy);

		std::string getInput(void)const;
		int getType(void)const;
		char getChar(void)const;
		int getInt(void)const;
		float getFloat(void)const;
		double getDouble(void)const;

		int checkInput(void);
		void convert(char *input);
		void printOutput(void)const;

		void fromChar(void);
		void fromInt(void);
		void fromFloat(void);
		void fromDouble(void);

		class ErrorException : public std::exception
		{
		public:
			virtual const char *what() const throw();
		};
};

#endif