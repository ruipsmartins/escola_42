#include "../includes/AMateria.hpp"

AMateria::AMateria(std::string const &type)
{
	this->_type = type;
	//std::cout << this->_type << " AMateria was created.\n";
}

AMateria::AMateria()
{
    this->_type = "default";
    //std::cout << "Default AMateria was created.\n";
}

AMateria::AMateria(AMateria const &src)
{
	//std::cout << "AMateria copy constructor called.\n";
	*this = src;
}

AMateria &AMateria::operator=(AMateria const &src)
{
	if (this != &src)
	{
		this->_type = src._type;
	}
	//std::cout << "AMateria copy assignment operator called.\n";
	return *this;
}

AMateria::~AMateria()
{
    //std::cout << "AMateria was destroyed.\n";
}

std::string const & AMateria::getType() const
{
	return (this->_type);
}

void AMateria::use(ICharacter& target)
{
	(void)target;
}

