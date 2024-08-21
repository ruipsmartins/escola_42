#include "Cat.hpp"

Cat::Cat() {
    _type = "Cat";
    std::cout << "Cat constructed.\n";
}

Cat::Cat(const Cat &other) : Animal(other) {
    _type = other._type;
    std::cout << "Cat copy constructed.\n";
}

Cat &Cat::operator=(const Cat &other) {
    if (this != &other) {
        Animal::operator=(other);
    }
    std::cout << "Cat assigned.\n";
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat destructed.\n";
}
        
void Cat::makeSound() const {
    std::cout << "Miiiaauuuu!\n";
}