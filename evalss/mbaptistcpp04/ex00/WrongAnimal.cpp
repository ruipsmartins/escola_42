#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal") {
    std::cout << "WrongAnimal constructed.\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : _type(other._type) {
    std::cout << "WrongAnimal copy constructed.\n";
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    if (this != &other) {
        _type = other._type;
    }
    std::cout << "WrongAnimal operator called\n";
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructed.\n";
}

void WrongAnimal::makeSound() const {
    std::cout << "WrongAnimal sound.\n";
}

std::string WrongAnimal::getType() const {
    return _type;
}