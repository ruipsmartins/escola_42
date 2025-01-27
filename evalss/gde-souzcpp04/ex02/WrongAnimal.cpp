#include "./WrongAnimal.hpp"

WrongAnimal::WrongAnimal(std::string type)
{
	this->_type = type;
	std::cout << this->_type << " WrongAnimal was created.\n";
}

WrongAnimal::WrongAnimal()
{
    this->_type = "default";
    std::cout << "Default WrongAnimal was created.\n";
}

WrongAnimal::WrongAnimal(WrongAnimal const &src)
{
	std::cout << " WrongAnimal copy constructor called.\n";
	*this = src;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &src)
{
	std::cout << "WrongAnimal copy assignment operator called.\n";
	if (this != &src)
	{
		this->_type = src._type;
	}
	return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal was destroyed.\n";
}

std::string WrongAnimal::getType() const
{
	return (this->_type);
}

void WrongAnimal::setType(std::string str)
{
	this->_type = str;
}

void WrongAnimal::makeSound() const
{
    std::cout << "*WRONG ANIMAL SOUND*\n";
}
