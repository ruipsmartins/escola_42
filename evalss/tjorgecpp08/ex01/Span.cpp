#include "Span.hpp"

// CONSTRUCTORS & DESTRUCTORS

Span::Span()
{
	//std::cout << "Span default constructor called\n";
	_vec.reserve(0);
}

Span::Span(unsigned int N)
{
	//std::cout << "Span default constructor called\n";
	_vec.reserve(N);
}

Span::Span(const Span &copy)
{
	//std::cout << "Span copy constructor called\n";
	*this = copy;
}

Span::~Span()
{
	//std::cout << "Span default destructor called\n";
}

// GETTERS


// SETTERS


// OPERATORS

Span&	Span::operator=(const Span &copy)
{
	//std::cout << "Span copy assignment operator called\n";
	//std::vector<int> new_vec;
	//new_vec.reserve(copy._vec.capacity());
	new_vec = copy._vec;
//	std::swap(this->_vec , new_vec);
	//this->_vec = new_vec;
	return (*this);
}

// MEMBER FUNCTIONS

void	Span::addNumber(int n)
{
	if (_vec.size() != _vec.capacity())
		_vec.push_back(n);
	else
		throw MaxCapacityReached();
}

void	Span::fillRandomly(int min, int max)
{
	if (_vec.size() == _vec.capacity())
		throw MaxCapacityReached();
	srand(time(NULL));
	while(_vec.size() != _vec.capacity())
		_vec.push_back(min + std::rand() % (max - min + 1));
}

void	Span::printVec()
{
	std::cout << "|";
	for (std::vector<int>::iterator i = _vec.begin(); i != _vec.end(); ++i)
        std::cout << " " << *i << " |";
	std::cout << std::endl;
}

int		Span::shortestSpan()
{
	if (_vec.size() < 2)
		throw LessThanTwoNumbers();

	std::vector<int> tmp = _vec;
	std::sort(tmp.begin(), tmp.end());
	int diff = *(tmp.end() - 1) - *tmp.begin();
	for (std::vector<int>::iterator i = tmp.begin(); i + 1 != tmp.end(); ++i)
	{
		if (*(i + 1) - *i < diff)
			diff = *(i + 1) - *i;
	}
	return (diff);
}

int		Span::longestSpan()
{
	if (_vec.size() < 2)
		throw LessThanTwoNumbers();
	return (*std::max_element(_vec.begin(), _vec.end()) - *std::min_element(_vec.begin(), _vec.end()));
}

const char*	Span::MaxCapacityReached::what() const throw()
{
	return ("The vector has already reached the max capacity");
}

const char*	Span::LessThanTwoNumbers::what() const throw()
{
	return ("The vector has less than two numbers");
}
