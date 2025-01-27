#ifndef SPAN_HPP
# define SPAN_HPP
# include <stdio.h>
# include <iostream>
# include <string.h>
# include <algorithm>
# include <fstream>
# include <vector>

class Span
{
	private:
		std::vector<int> _vec;

	public:
		Span();
		Span(unsigned int N);
		Span(const Span &a);
		~Span() ;

		Span&	operator=(const Span &copy);
		
		void	addNumber(int n);
		void	fillRandomly(int min, int max);
		int		shortestSpan();
		int		longestSpan();
		void	printVec();

	class	MaxCapacityReached: public std::exception
	{
		virtual const char* what() const throw();
	};

	class	LessThanTwoNumbers: public std::exception
	{
		virtual const char* what() const throw();
	};
};

#endif