#include "./Animal.hpp"
#include "./Dog.hpp"
#include "./Cat.hpp"

#define SIZE 10

int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    //const Animal* w = new Animal();
    Animal* arr[SIZE + 1];

    std::cout << std::endl;

    for (int i = 0; i < SIZE; i++)
    {
        if (i < SIZE / 2)
            arr[i] = new Dog();
        else
            arr[i] = new Cat();
        arr[i]->makeSound();
        std::cout << std::endl;
    }

    for (int i = 0; i < SIZE; i++)
        delete arr[i];

    std::cout << std::endl;

    delete j;//should not create a leak
    delete i;

    return 0;
}
