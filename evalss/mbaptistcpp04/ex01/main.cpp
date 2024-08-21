#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    const int animalCount = 7;
    Animal* animals[animalCount];

    for (int i = 0; i < animalCount / 2; ++i) {
        animals[i] = new Dog();
    }
    for (int i = animalCount / 2; i < animalCount; ++i) {
        animals[i] = new Cat();
    }

    for (int i = 0; i < animalCount; ++i) {
        animals[i]->makeSound();
    }

    for (int i = 0; i < animalCount; ++i) {
        delete animals[i];
    }

    // Test deep copy vs shalow
    Dog originalDog;
    originalDog.getBrain()->setIdea(0, "Chew my sneakers!");
    Dog copiedDog = originalDog;
    // copiedDog.getBrain()->setIdea(0, "Sleep & sleep!");
    std::cout << "\n";

    std::cout << "Original Dog Brain Idea:    " << originalDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copied Dog Brain Idea:      " << copiedDog.getBrain()->getIdea(0) << std::endl;

    return 0;
}