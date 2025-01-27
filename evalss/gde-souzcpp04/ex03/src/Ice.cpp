#include "../includes/Ice.hpp"

Ice::Ice(std::string const & type) : AMateria(type)
{
	this->_type= "ice";
    //std::cout << "Ice was created.\n";
}

Ice::Ice() : AMateria()
{
    this->_type= "ice";
    //std::cout << "Ice was created.\n";
}

Ice::Ice(Ice const &src) : AMateria(src)
{
	*this = src;
	//std::cout << "Ice copy constructor called.\n";
}

Ice &Ice::operator=(Ice const &src)
{
	if (this != &src)
		this->_type = src._type;
	//std::cout << "Ice copy assignment operator called.\n";
	return *this;
}

Ice::~Ice()
{
    //std::cout << "Ice was destroyed.\n";
}

Ice* Ice::clone() const
{
	return (new Ice());
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
	return ;
}
