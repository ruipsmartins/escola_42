#ifndef RPN_HPP
# define RPN_HPP
# include <iostream>
# include <iomanip>
# include <stack>

class RPN
{
private:
	std::stack<int>	_st;
	size_t			_operators;
	size_t			_numbers;
public:
	RPN();
	RPN(const RPN& ref);
	RPN&	operator=(const RPN& ref);
	~RPN();

	int		getFromStack();
	void	startStack(std::string inp);
	void	calculate(char c);
};

#endif