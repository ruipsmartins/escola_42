#include "./Animal.hpp"

Animal::Animal(std::string type)
{
	this->_type = type;
	std::cout << this->_type << " Animal was created.\n";
}

Animal::Animal()
{
    this->_type = "default";
    std::cout << "Default Animal was created.\n";
}

Animal::Animal(Animal const &src)
{
	std::cout << "Animal copy constructor called.\n";
	*this = src;
}

Animal &Animal::operator=(Animal const &src)
{
	std::cout << "Animal copy assignment operator called.\n";
	if (this != &src)
	{
		this->_type = src._type;
	}
	return *this;
}

Animal::~Animal()
{
    std::cout << "Animal was destroyed.\n";
}

std::string Animal::getType() const
{
	return (this->_type);
}

void Animal::setType(std::string str)
{
	this->_type = str;
}

void Animal::makeSound() const
{
    std::cout << "*ANIMAL SOUND*\n";
}
