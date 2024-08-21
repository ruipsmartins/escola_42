#include "AMateria.hpp"

// Default Constructor
AMateria::AMateria() : _type("") {}

// My Constructor
AMateria::AMateria(std::string const &other) : _type(other) {}

// Copy assignment operator
AMateria &AMateria::operator=(const AMateria &other) {
    if (this != &other) {
        _type = other._type;
    }
    return *this;
}

// Copy constructor
AMateria::AMateria(const AMateria &other) : _type(other._type) {}

// Destructor
AMateria::~AMateria() {}


std::string const & AMateria::getType() const {
    return _type;
}

void AMateria::use(ICharacter& target) {
    std::cout << "* uses " << _type << " on " << target.getName() << " *" << std::endl;
}
