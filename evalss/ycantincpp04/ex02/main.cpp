/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 21:00:55 by yohan             #+#    #+#             */
/*   Updated: 2025/02/13 23:21:39 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Animal.hpp"
#include "include/Cat.hpp"
#include "include/Dog.hpp"
#include "include/WrongAnimal.hpp"
#include "include/WrongCat.hpp"

int main(void)
{
    AAnimal *cat = new Cat();
    AAnimal *dog = new  Dog();
    AAnimal *animal = new AAnimal(); // will give you abstract class warning

    cat->makeSound();
    dog->makeSound();

    cat->setBrainThought("yo whats up", 2);
    std::cout << "cat thought: " << cat->getBrainThought(2) << std::endl;
    std::cout << "dog thought: " << dog->getBrainThought(1)<< std::endl;
    delete(cat);
    delete(dog);
}