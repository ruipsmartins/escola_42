#include "Span.hpp"

int main()
{
	Span vec(10);
	try
	{
		vec.addNumber(42);
		vec.addNumber(3);
		vec.fillRandomly(-1000, 1000);
		std::cout << "----- VECTOR -----" << std::endl;
		vec.printVec();
		std::cout << "Longest span = " << vec.longestSpan() << std::endl;
		std::cout << "Shortest span = " << vec.shortestSpan() << std::endl;
		vec.addNumber(404);
		std::cout << "I shouldn't print this!";
	}
	catch(const std::exception& e)
	{
		std::cerr << "ERROR: " << e.what() << std::endl;
	}

	std::cout << std::endl << "----- SMALL VECTOR -----" << std::endl;
	Span small_vec(3);
	try
	{
		std::cout << "Longest span = " << small_vec.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		small_vec.addNumber(1000);
		std::cout << "Shortest span = " << small_vec.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		small_vec.addNumber(-1000);
		small_vec.printVec();
		std::cout << "Longest span = " << small_vec.longestSpan() << std::endl;
		std::cout << "Shortest span = " << small_vec.shortestSpan() << std::endl;
		
		std::cout << std::endl << "----- COPY ASSIGNMENT TEST -----" << std::endl;
		vec = small_vec;
		vec.addNumber(42);
		//vec.addNumber(42);
		//vec.fillRandomly(-1000, 1000);
		vec.printVec();
		small_vec.printVec();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

/*int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return 0;
}*/