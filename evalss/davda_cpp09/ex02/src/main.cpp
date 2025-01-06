#include "../inc/PmergeMe.hpp"

int	main(int ac, char **av)
{
	PmergeMe	out;
	try
	{
		if (ac < 2)
		{
			std::cerr << "Error, invalid number of arguments" << std::endl;
			exit(1);
		}
		else if (ac == 2)
		{
			std::istringstream	ch(av[1]);
			std::string		buff = "";
			while (ch >> buff)
				out.checkInp(buff);
		}
		else
		{
			for (int i = 1; i < ac; i++)
				out.checkInp(av[i]);
		}
		out.startAlg();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}