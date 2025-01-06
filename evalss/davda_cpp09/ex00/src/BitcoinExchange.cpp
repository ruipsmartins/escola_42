#include "../inc/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	_prev = "";
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& ref)
{
	*this = ref;
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& ref)
{
	if (this != &ref)
	{
		this->_cont = ref._cont;
		this->_prev = ref._prev;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange(){}

bool	BitcoinExchange::checkDate(std::string date)
{
	int year, month, day;
	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	std::string yearSize = date.substr(0, 4);

	if (yearSize.size() != 4)
		return false;
	year = std::stoi(yearSize);
	month = std::stoi(date.substr(5, 2));
	day = std::stoi(date.substr(8, 2));
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		daysInMonth[1] = 29;
	if (year < 1)
		return false;
	else if (month < 1 || month > 12)
		return false;
	else if (day < 1 || day > daysInMonth[month - 1])
		return false;
	return true;
}

bool	BitcoinExchange::checkValue(std::string value)
{
	if (value.length() > 0 && value.find_first_not_of("+-0123456789.") == std::string::npos)
	{
		if (value[0] == '+' || value[0] == '-')
		{
			if (value.length() == 1 || value.find_first_not_of("0123456789.", 1) != std::string::npos)
				return false;
		}
		if (value.find_first_of(".") != value.find_last_of("."))
			return false;
		if (value.back() == '.' || value.front() == '.')
			return false;
	}
	return true;
}

#include <list>

bool	BitcoinExchange::checkDataLine(std::string buff)
{
	std::string	date;
	std::string	value;
	float		v;

	for (int i = 0; buff[i]; i++)
	{
		if (i == 4 || i == 7)
		{
			if (buff[i] != '-')
				return false;
		}
		else if (i == 10)
		{
			if (buff[i] != ',')
				return false;
		}
		else if (std::isdigit(buff[i]) == 0 && buff[i] != '.')
			return false;
	}
	date = buff.substr(0, 10);
	if (date.length() != 10)
		return false;
	if (date < _prev)
		return false;
	_prev = date;
	if (checkDate(date) == false)
		return false;
	value = buff.substr(11, buff.size());
	if (checkValue(value) == false)
		return false;
	v = atof(value.c_str());
	if (v < 0.00 || v > 2147483647.00)
		return false;
	this->_cont[date] = v;
	return true;
}

float	BitcoinExchange::getDate(std::string inp)
{
	std::map<std::string, float>::iterator	i = _cont.lower_bound(inp);
	if (i == _cont.begin())
		return	i->second;
	std::map<std::string, float>::iterator	previ = i;
	previ--;
	if (i == _cont.end())
		return previ->second;
	if (std::abs(inp.compare(i->first)) < std::abs(inp.compare(previ->first)))
		return i->second;
	else
		return previ->second;
}

void	BitcoinExchange::checkInputLine(std::string file)
{
	std::string	date;
	std::string	value;
	float		v;
	float		res_v;

	for (int i = 0; file[i]; i++)
	{
		if (i == 4 || i == 7)
		{
			if (file[i] != '-')
			{
				std::cout << "Error: bad input => " << file << std::endl;
				return;
			}
		}
		else if ((i == 10 && file[i] != ' ') || (i == 11 && file[i] != '|') || (i == 12 && file[i] != ' '))
		{
			std::cout << "Error: bad input => " << file << std::endl;
			return;
		}
		else if (std::isdigit(file[i]) == 0 && (file[i] != '.' && file[i] != ' ' && file[i] != '|' && file[i] != '-'))
		{
			std::cout << "Error: bad input => " << file << std::endl;
			return;
		}
	}
	date = file.substr(0, 10);
	if (date.length() != 10)
	{
		std::cout << "Error: bad input => " << file << std::endl;
		return;
	}
	if (checkDate(date) == false || date < _cont.begin()->first)
	{
		std::cout << "Error: bad input => " << file << std::endl;
		return;
	}
	value = file.substr(13, file.size());
	v = atof(value.c_str());
	if (checkValue(value) == false)
	{
		std::cout << "Error: not a valid number." << std::endl;
		return;
	}
	if (v < 0.00)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return;
	}
	else if (v > 1000.00)
	{
		std::cout << "Error: too large a number." << std::endl;
		return;
	}
	res_v = getDate(date);
	std::cout << std::fixed << std::setprecision(2);
	std::cout << date << " => " << value << " = " << res_v * v << std::endl;
}

void	BitcoinExchange::parsingData()
{
	std::ifstream f("data.csv");
	std::string fline;
	if (!f.is_open())
		throw std::invalid_argument("Couldn't open data file");
	getline(f, fline);
	if (fline != "date,exchange_rate")
		throw std::invalid_argument("Data file not valid");
	while(getline(f, fline))
	{
		if (checkDataLine(fline) == false)
			throw std::invalid_argument("Data file not valid");
	}
}

void	BitcoinExchange::parsingInput(std::string& file)
{
	std::ifstream f;
	std::string buff;
	f.open(file);
	if (!f.is_open())
		throw std::invalid_argument("Couldn't open file");
	getline(f, buff);
	if (buff != "date | value")
		throw std::invalid_argument("Input file not valid");
	while(getline(f, buff))
		checkInputLine(buff);
}
