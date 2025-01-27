#include "./WrongCat.hpp"

WrongCat::WrongCat(std::string type) : WrongAnimal(type)
{
    std::cout << this->_type << " WrongCat was created.\n";
}

WrongCat::WrongCat() : WrongAnimal()
{
    this->_type= "default";
    std::cout << "Default WrongCat was created.\n";
}

WrongCat::WrongCat(WrongCat const &src) : WrongAnimal(src)
{
	std::cout << "WrongCat copy constructor called.\n";
	*this = src;
}

WrongCat &WrongCat::operator=(WrongCat const &src)
{
	std::cout << "WrongCat copy assignment operator called.\n";
	if (this != &src)
	{
		this->_type = src._type;
	}
	return *this;
}

WrongCat::~WrongCat()
{
    std::cout << this->_type << " WrongCat was destroyed.\n";
}

void WrongCat::makeSound() const
{
	std::cout << "Wrong Miau! 😿\n";
}
