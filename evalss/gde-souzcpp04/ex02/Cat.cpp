#include "./Cat.hpp"

Cat::Cat(std::string type) : Animal(type)
{
	this->_type= "Cat";
	this->brain = new Brain();
    std::cout << this->_type << " Cat was created.\n";
}

Cat::Cat() : Animal()
{
    this->_type= "Cat";
	this->brain = new Brain();
    std::cout << "Cat was created.\n";
}

Cat::Cat(Cat const &src) : Animal(src)
{
	*this = src;
	this->brain = new Brain(*src.brain);
	std::cout << "Cat copy constructor called.\n";
}

Cat &Cat::operator=(Cat const &src)
{
	std::cout << "Cat copy assignment operator called.\n";
	if (this != &src)
	{
		this->_type = src._type;
		delete this->brain;
        this->brain = new Brain(*src.brain);
	}
	return *this;
}

Cat::~Cat()
{
	delete this->brain;
    std::cout << "Cat was destroyed.\n";
}

void Cat::makeSound() const
{
	std::cout << "Miau! 🐱\n";
}
