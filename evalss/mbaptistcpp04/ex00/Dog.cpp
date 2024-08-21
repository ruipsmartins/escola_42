#include "Dog.hpp"

Dog::Dog() {
    _type = "Dog";
    std::cout << "Dog constructed.\n";
}

Dog::Dog(const Dog &other) : Animal(other) {
    _type = other._type;
    std::cout << "Dog copy constructed.\n";
}

Dog &Dog::operator=(const Dog &other) {
    if (this != &other) {
        Animal::operator=(other);
    }
    std::cout << "Dog assigned.\n";
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog destructed.\n";
}
        
void Dog::makeSound() const {
    std::cout << "woooooooff!\n";
}