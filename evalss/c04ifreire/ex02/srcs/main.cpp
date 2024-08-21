/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 20:33:06 by ifreire-          #+#    #+#             */
/*   Updated: 2024/01/29 11:44:57 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Brain.hpp"

int main() 
{
    std::cout << "\n------------TestLeaks------------\n" << std::endl; 
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;
    delete i;
    
    /*std::cout << "\n\n------------TestDeepCopies------------\n" << std::endl;

    Animal animal1;
    Animal animal2 = animal1;

    std::cout << "\n" << std::endl;
    std::cout << animal1.getType() << std::endl;  // Animal
    std::cout << animal2.getType() << std::endl;  // Animal

    animal1.setType("Modified Animal");
    std::cout << "\nAnimal1 Modified\n" << std::endl;
    std::cout << animal1.getType() << std::endl; // Modified Animal
    std::cout << animal2.getType() << "\n" << std::endl; // Animal*/

    std::cout << "\n\n------------Main_1------------\n" << std::endl;
    Animal* animalp[3];

    animalp[0] = new (Dog);
    animalp[1] = new (Dog);
    animalp[2] = new (Cat);

    delete animalp[0];
    delete animalp[1];
    delete animalp[2];

    std::cout << "\n\n------------Main_2------------\n" << std::endl;
    int size = 6;
    Animal* animals[size];
    for (int i = 0; i < size / 2; i++) 
        animals[i] = new Dog();
    for (int i = size / 2; i < size; i++) 
        animals[i] = new Cat();
    for (int i = 0; i < size; i++) 
    {
        animals[i]->makeSound();
        animals[i]->idea(0, "Running");
    }
    animals[0]->makeSound();
    animals[0]->idea(0, "EATING ALOT OF MEAT");
    animals[0]->ideaN(0);
    animals[1]->ideaN(0);
    animals[5]->makeSound();

    for (int i = 0; i < size; i++) 
    {
        delete animals[i];
    }

    std::cout << "\n------------Assignment_Stack------------\n" << std::endl; 
    Dog dog1;

    Dog dog2 = dog1;

    std::cout << "\n------------Assignment_Heap------------\n" << std::endl; 
    /*Dog l;

    Animal Obj5(l);
    Animal Obj6 = Dog(l);

    Animal *Obj7 = new Dog(l);
    delete Obj7;

    std::cout << "\n------------Copy_Stack------------\n" << std::endl; 
    Animal obj1;
    Animal obj2 = obj1; //obj2(obj1); 

    std::cout << "\n------------Copy_Heap------------\n" << std::endl;
    Animal *obj3 = new Animal();
    Animal *obj4 = new Animal(*obj3);

    delete obj3;
    delete obj4;*/
	
    Dog a = Dog();
    Dog b = Dog();
    b = a;
}
