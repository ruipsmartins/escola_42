#include "Cat.hpp"

Cat::Cat() : Animal(), brain(new Brain()) {//////
    _type = "Cat";
    std::cout << "Cat constructed.\n";
}

Cat::Cat(const Cat &other): Animal(other), brain(new Brain(*other.brain)) {
    _type = other._type; //////////
    std::cout << "Cat copy constructed.\n";
}

Cat &Cat::operator=(const Cat &other) {
    if (this != &other) {
        Animal::operator=(other);
        *brain = *other.brain; 
    }
    std::cout << "Cat assigned.\n";
    return *this;
}

Cat::~Cat() {
    delete brain;
    std::cout << "Cat destructed.\n";
}
        
void Cat::makeSound() const {
    std::cout << "Miiiaauuuu!\n";
}

Brain *Cat::getBrain() const {
    return brain;
}

