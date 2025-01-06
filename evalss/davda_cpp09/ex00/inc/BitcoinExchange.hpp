#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <iostream>
# include <iomanip>
# include <limits>
# include <fstream>
# include <sstream>
# include <map>
# include <algorithm>

class BitcoinExchange
{
private:
	std::map<std::string, float>	_cont;
	std::string						_prev;
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& ref);
	BitcoinExchange&	operator=(const BitcoinExchange& ref);
	~BitcoinExchange();

	void	parsingInput(std::string&	file);
	void	checkInputLine(std::string file);
	void	parsingData();
	bool	checkDataLine(std::string buff);
	bool	checkDate(std::string date);
	bool	checkValue(std::string value);

	float	getDate(std::string inp);
};

#endif