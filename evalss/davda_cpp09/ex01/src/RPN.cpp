#include "../inc/RPN.hpp"

RPN::RPN()
{
	_operators = _numbers = 0;
}

RPN::RPN(const RPN& ref)
{
	*this = ref;
}

RPN&	RPN::operator=(const RPN& ref)
{
	if (this != &ref)
	{
		this->_st = ref._st;
		this->_numbers = ref._numbers;
		this->_operators = ref._operators;
	}
	return *this;
}

RPN::~RPN(){}

void	RPN::startStack(std::string	inp)
{
	std::string	op = "+-/*";

	if (inp.size() < 4)
		throw std::invalid_argument("Error");
	for (int i = 0; i < inp.length(); i++)
	{
		if (inp[i] == ' ')
			continue;
		else if (isdigit(inp[i]) && inp[i + 1] == ' ')
		{
			_numbers++;
			_st.push(inp[i] - '0');
		}
		else if ((!isdigit(inp[i]) && op.find(inp[i]) != std::string::npos) && _st.size() >= 2)
		{
			_operators++;
			calculate(inp[i]);
		}
		else
			throw std::invalid_argument("Error");
	}
	if ((_operators + 1) != _numbers)
		throw std::invalid_argument("Error, incorrect ammount of numbers and/or operators");
	std::cout << _st.top() << std::endl;
}

int		RPN::getFromStack()
{
	int res = _st.top();
	_st.pop();
	return res;
}

void	RPN::calculate(char c)
{
	int nb1 = getFromStack();
	int nb2 = _st.top();
	switch (c)
	{
	case '+':
		_st.top() = nb1 + nb2;
		break;
	case '-':
		_st.top() = nb2 - nb1;
		break;
	case '*':
		_st.top() = nb2 * nb1;
		break;
	case '/':
		_st.top() = nb2 / nb1;
		break;
	default:
		throw std::invalid_argument("Error");
	}
}