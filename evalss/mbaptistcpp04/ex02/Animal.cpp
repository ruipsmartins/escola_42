#include "Animal.hpp"

Animal::Animal() : _type("Animal") {
    std::cout << "Animal constructed.\n";
}

Animal::Animal(const Animal &other) : _type(other._type) {
    std::cout << "Animal copy constructed.\n";
}

Animal &Animal::operator=(const Animal &other) {
    if (this != &other) {
        _type = other._type;
    }
    std::cout << "Animal assigned.\n";
    return *this;
}

Animal::~Animal() {
    std::cout << "Animal destructed.\n";
}

// void Animal::makeSound() const {
//     std::cout << "Animal sound.\n";
// }

std::string Animal::getType() const {
    return _type;
}
