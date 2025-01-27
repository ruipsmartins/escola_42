#include "./Dog.hpp"

Dog::Dog(std::string type) : Animal(type)
{
	this->_type= "Dog";
	this->brain = new Brain();
    std::cout << "Dog was created.\n";
}

Dog::Dog() : Animal()
{
    this->_type= "Dog";
	this->brain = new Brain();
    std::cout << "Dog was created.\n";
}

Dog::Dog(Dog const &src) : Animal(src)
{
	*this = src;
	this->brain = new Brain(*src.brain);
	std::cout << "Dog copy constructor called.\n";
}

Dog &Dog::operator=(Dog const &src)
{
	std::cout << "Dog copy assignment operator called.\n";
	if (this != &src)
	{
		this->_type = src._type;
		delete this->brain;
        this->brain = new Brain(*src.brain);
	}
	return *this;
}

Dog::~Dog()
{
	delete this->brain;
    std::cout << "Dog was destroyed.\n";
}

void Dog::makeSound() const
{
	std::cout << "Au-au! 🐶\n";
}
