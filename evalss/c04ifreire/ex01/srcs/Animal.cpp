#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"

Animal::Animal(void) : type("Animal")
{
    std::cout << getType() << " Default Constructor called" << std::endl;
}

Animal::Animal(Animal const &src)
{
    std::cout << "Animal Copy constructor called" << std::endl;
    type = src.type;
}

Animal &Animal::operator=(Animal const &rhs)
{
    std::cout  <<"Animal Assignment constructor called " << std::endl;
    if (this != &rhs)
        type = rhs.type;
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal Destructor called" << std::endl;
}

void Animal::makeSound() const
{
    std::cout << "Weird noise" << std::endl;
}

std::string Animal::getType(void) const
{
    return (type);
}

void Animal::setType(std::string types)
{
    type = types;
}

void Animal::idea(int i, std::string str) const
{
    (void)i;
    (void)str;
}

void Animal::ideaN(int i) const
{
    (void)i;
}
