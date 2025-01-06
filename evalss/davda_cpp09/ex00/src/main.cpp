#include "../inc/BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Invalid arguments!" << std::endl;
		return 1;
	}
	std::string file = av[1];
	BitcoinExchange	btc;
	try
	{
		btc.parsingData();
		btc.parsingInput(file);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}