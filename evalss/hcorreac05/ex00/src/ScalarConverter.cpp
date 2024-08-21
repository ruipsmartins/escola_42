#include "../inc/ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
}

ScalarConverter::~ScalarConverter() {
}

ScalarConverter::ScalarConverter(const ScalarConverter& copy) {
	std::cout << "Default copy constructor called" << std::endl;
	*this = copy;
	this->printOutput();
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& copy) {
	std::cout << "Default assignment operator called" << std::endl;
	(void)copy;
	return (*this);
}

int	ScalarConverter::checkInput() {
	if (this->getInput().compare("nan") == 0 || this->getInput().compare("nanf") == 0 ||
		this->getInput().compare("+inf") == 0 || this->getInput().compare("-inf") == 0 ||
		this->getInput().compare("+inff") == 0 || this->getInput().compare("-inff") == 0)
		return (NAN_INF);
	else if (this->getInput().length() == 1 &&
		(this->getInput()[0] == '+' || this->getInput()[0] == '-' || // "+" or "-"
		this->getInput()[0] == 'f' || this->getInput()[0] == '.')) // "f" of "."
		return (CHAR);
	else if (this->getInput().find_first_of("+-") != this->getInput().find_last_of("+-"))
		return (ERROR);
	else if (this->getInput().find_first_not_of("+-0123456789") == std::string::npos)
		return (INT);
	else if (this->getInput().find_first_not_of("+-0123456789.") == std::string::npos)
	{
		if (this->getInput().find_first_of(".") != this->getInput().find_last_of(".") || // "0..0"
			isdigit(this->getInput()[this->getInput().find_first_of(".") + 1]) == false || // "0."
			this->getInput().find_first_of(".") == 0) // ".0"
			return (ERROR);
		else
			return (DOUBLE);
	}
	else if (this->getInput().find_first_not_of("+-0123456789.f") == std::string::npos)
	{
		if (this->getInput().find_first_of("f") != this->getInput().find_last_of("f") || //0.0ff
			this->getInput().find_first_of(".") != this->getInput().find_last_of(".") || // "0..0f"
			this->getInput().find_first_of("f") - this->getInput().find_first_of(".") == 1 || // "0.f"
			this->getInput().find_first_of(".") == 0 || // ".0f"
			this->getInput()[this->getInput().find_first_of("f") + 1] != '\0') // "0.0f0"
			return (ERROR);
		else
			return (FLOAT);
	}
	else if ((this->getInput().length() == 1 && std::isprint(this->getInput()[0])) ||
		(this->getInput().length() == 1 && std::isalpha(this->getInput()[0])))
		return (CHAR);
	else
		return (ERROR);
}

void ScalarConverter::fromChar(void) {
	this->_char = static_cast<unsigned char>(this->getInput()[0]);
	this->_int = static_cast<int>(this->getChar());
	this->_float = static_cast<float>(this->getChar());
	this->_double = static_cast<double>(this->getChar());
}

void ScalarConverter::fromInt(void) {
	this->_int = atoi(this->getInput().c_str());
	this->_double = static_cast<double>(this->getInt());
	this->_char = static_cast<unsigned char>(this->getInt());
	this->_float = static_cast<float>(this->getInt());
}

void ScalarConverter::fromFloat(void) {
	this->_float = atof(this->getInput().c_str());
	this->_char = static_cast<char>(this->getFloat());
	this->_int = static_cast<int>(this->getFloat());
	this->_double = static_cast<double>(this->getFloat());
}

void ScalarConverter::fromDouble(void) {
	this->_double = atof(this->getInput().c_str());
	this->_char = static_cast<char>(this->getDouble());
	this->_int = static_cast<int>(this->getDouble());
	this->_float = static_cast<float>(this->getDouble());
}

void	ScalarConverter::convert(char *input)
{
	void (ScalarConverter::*functionPTRS[])(void) = {&ScalarConverter::fromChar, &ScalarConverter::fromInt, &ScalarConverter::fromFloat, &ScalarConverter::fromDouble};
	int types[] = {CHAR, INT, FLOAT, DOUBLE};

	this->_input = input;
	this->_type = checkInput();

	if (this->getType() == NAN_INF)
		return ;
	int i;
	for (i = 0; i < 4; i++)
	{
		if (this->getType() == types[i])
		{
			(this->*functionPTRS[i])();
			break ;
		}
	}
	if (i == 4)
		throw ScalarConverter::ErrorException();
}

void	ScalarConverter::printOutput(void)const
{
	// display char
	if (this->getType() != NAN_INF && this->getDouble() <= UCHAR_MAX && this->getDouble() >= 0)
	{
		if (isprint(this->getChar()))
			std::cout << "char: '" << this->getChar() << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl;

	// display int
	//std::cout << "getInt() = " << this->getInt() << " max int = " << std::numeric_limits<int>::max() << std::endl;
	if (this->getType() == NAN_INF)
		std::cout << "int: impossible" << std::endl;
	else if (atof(this->getInput().c_str()) > std::numeric_limits<int>::max() || atof(this->getInput().c_str()) < std::numeric_limits<int>::min())
		std::cout << "int (overflowed): " << this->getInt() << std::endl;
	else
		std::cout << "int: " << this->getInt() << std::endl;

	// display float
	if (this->getType() != NAN_INF)
	{
		std::cout << "float: " << this->getFloat();
		if (this->getFloat() - this->getInt() == 0)
			std::cout << ".0f" << std::endl;
		else
			std::cout << "f" << std::endl;
	}
	else
	{
		if (this->getInput() == "nan" || this->getInput() == "nanf")
			std::cout << "float: nanf" << std::endl;
		else if (this->getInput()[0] == '+')
			std::cout << "float: +inff" << std::endl;
		else
			std::cout << "float: -inff" << std::endl;
	}

	// display double
	if (this->getType() != NAN_INF)
	{
		std::cout << "double: " << this->getDouble();
		if (this->getDouble() < std::numeric_limits<int>::min() || this->getDouble() > std::numeric_limits<int>::max() ||
			this->getDouble() - this->getInt() == 0)
			std::cout << ".0" << std::endl;
		else
			std::cout << std::endl;
	}
	else
	{
		if (this->getInput() == "nan" || this->getInput() == "nanf")
			std::cout << "double: nan" << std::endl;
		else if (this->getInput()[0] == '+')
			std::cout << "double: +inf" << std::endl;
		else
			std::cout << "double: -inf" << std::endl;
	}
}

std::string	ScalarConverter::getInput(void)const
{
	return (this->_input);
}

int	ScalarConverter::getType(void)const
{
	return (this->_type);
}

char	ScalarConverter::getChar(void)const
{
	return (this->_char);
}

int	ScalarConverter::getInt(void)const
{
	return (this->_int);
}

float	ScalarConverter::getFloat(void)const
{
	return (this->_float);
}

double ScalarConverter::getDouble(void)const
{
	return (this->_double);
}

const char *ScalarConverter::ErrorException::what(void) const throw()
{
	return ("Error: Impossible to print or input not convertable");
};