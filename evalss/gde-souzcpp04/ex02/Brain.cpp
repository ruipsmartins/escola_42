#include "./Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain was created.\n";
}

Brain::Brain(Brain const &src)
{
    *this = src;
    std::cout << "Brain copy constructor called.\n";
}

Brain &Brain::operator=(Brain const &src)
{
    std::cout << "Brain copy assignment operator called.\n";
	if (this != &src)
	{
		for (int i = 0; i < 100; i++)
            this->_ideas[i] = src._ideas[i];
	}
	return *this;
}

Brain::~Brain()
{
    std::cout << "Brain was destroyed.\n";
}