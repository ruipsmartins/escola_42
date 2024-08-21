#include "WrongCat.hpp"

WrongCat::WrongCat() {
    _type = "WrongCat";
    std::cout << "WrongCat constructed.\n";
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
    _type = other._type;
    std::cout << "WrongCat copy constructed.\n";
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
    if (this != &other) {
        WrongAnimal::operator=(other);
    }
    std::cout << "WrongCat assigned.\n";
    return *this;
}
WrongCat::~WrongCat() {
    std::cout << "WrongCat destructed.\n";
}
        
void WrongCat::makeSound() const {
    std::cout << "WrongCat blablabla!\n";
}