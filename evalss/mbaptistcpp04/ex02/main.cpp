#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
 {
    const int numAnimals = 4;
    Animal* animals[numAnimals];

    // Animal alex;
    
    for (int i = 0; i < numAnimals / 2; ++i) {
        animals[i] = new Dog();
    }
    std::cout << "\n";
    for (int i = numAnimals / 2; i < numAnimals; ++i) {
        animals[i] = new Cat();
    }
    std::cout << "\n";
    for (int i = 0; i < numAnimals; ++i) {
        animals[i]->makeSound();
    }
    std::cout << "\n";
    for (int i = 0; i < numAnimals; ++i) {
        delete animals[i];
    }

    return 0;
}