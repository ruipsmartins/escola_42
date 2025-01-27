#include "./Dog.hpp"

Dog::Dog(std::string type) : Animal(type)
{
    std::cout << this->_type << " Dog was created.\n";
}

Dog::Dog() : Animal()
{
    this->_type= "default";
    std::cout << "Default Dog was created.\n";
}

Dog::Dog(Dog const &src) : Animal(src)
{
	std::cout << "Dog copy constructor called.\n";
	*this = src;
}

Dog &Dog::operator=(Dog const &src)
{
	std::cout << "Dog copy assignment operator called.\n";
	if (this != &src)
	{
		this->_type = src._type;
	}
	return *this;
}

Dog::~Dog()
{
    std::cout << this->_type << " Dog was destroyed.\n";
}

void Dog::makeSound() const
{
	std::cout << "Au-au! 🐶\n";
}
