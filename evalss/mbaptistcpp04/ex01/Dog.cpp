#include "Dog.hpp"

Dog::Dog() : Animal(), brain(new Brain()) {
    _type = "Dog";
    std::cout << "Dog constructed.\n";
}

Dog::Dog(const Dog &other) : Animal(other), brain(new Brain(*other.brain)) {
    _type = other._type;
    std::cout << "Dog copy constructed.\n";
}

Dog &Dog::operator=(const Dog &other) {
    if (this != &other) {
        Animal::operator=(other);
        *brain = *other.brain;
    }
    std::cout << "Dog assigned.\n";
    return *this;
}

Dog::~Dog() {
    delete brain;
    std::cout << "Dog destructed.\n";
}
        
void Dog::makeSound() const {
    std::cout << "Aaaaaaaoooo!\n";
}

Brain *Dog::getBrain() const {
    return brain;
}