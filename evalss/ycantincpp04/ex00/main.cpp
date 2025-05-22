/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 21:00:55 by yohan             #+#    #+#             */
/*   Updated: 2025/02/13 19:24:20 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
    Animal *dog = new Dog();
    Animal *cat = new Cat();
    Animal *unknown = new Animal();
    
    std::cout << "Dog now talking. lets listen:\n";
    dog->makeSound();
    std::cout << std::endl;

    std::cout << "Cat is now talking. lets listen:\n";
    cat->makeSound();
    std::cout << std::endl;

    std::cout << "Unkown animal is now talking. lets listen:\n";
    unknown->makeSound();
    std::cout << std::endl;

    delete (cat);
    std::cout << "Cat is now Dog:\n";
    cat = dog;
    std::cout << "cat that is now dog is talking. lets listen:\n";
    cat->makeSound();
    std::cout << std::endl;

    WrongAnimal *wrongAnimal = new WrongAnimal();
    WrongCat *notACat = new WrongCat();
    std::cout << "wrong animal is now talking. lets listen:\n";
    wrongAnimal->makeSound();
    std::cout << std::endl;
    
    std::cout << "wrong cat is now talking. lets listen:\n";
    notACat->makeSound();
    std::cout << std::endl;
    
    delete(wrongAnimal);
    std::cout << "wrong animal is now a wrong cat. lets listen:\n";
    wrongAnimal = notACat;
    wrongAnimal->makeSound();
    std::cout << std::endl;
    
    delete(dog);
    delete(unknown);
    delete(notACat);
}