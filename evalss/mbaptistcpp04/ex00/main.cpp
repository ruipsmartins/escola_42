#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    std::cout << meta->getType() << " " << std::endl;
    meta->makeSound();
    delete i;
    delete j;
    delete meta;
    std::cout << "\n";

    const WrongAnimal *b = new WrongAnimal();
    std::cout << b->getType() << " " << std::endl;
    b->makeSound();
    const WrongAnimal *c = new WrongCat();
    std::cout << c->getType() << " " << std::endl;
    c->makeSound();
    delete b;
    delete c;

    std::cout << "\n";
    

    return 0;
}