#include "../includes/Cure.hpp"

Cure::Cure(std::string const & type) : AMateria(type)
{
	this->_type= "cure";
   // std::cout << "Cure was created.\n";
}

Cure::Cure() : AMateria()
{
    this->_type= "cure";
   // std::cout << "Cure was created.\n";
}

Cure::Cure(Cure const &src) : AMateria(src)
{
	*this = src;
	//std::cout << "Cure copy constructor called.\n";
}

Cure &Cure::operator=(Cure const &src)
{
	//std::cout << "Cure copy assignment operator called.\n";
	if (this != &src)
		this->_type = src._type;
	return *this;
}

Cure::~Cure()
{
    //std::cout << "Cure was destroyed.\n";
}

Cure* Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *\n";
	return ;
}
