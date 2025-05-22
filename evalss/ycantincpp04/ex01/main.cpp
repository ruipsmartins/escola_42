/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 21:00:55 by yohan             #+#    #+#             */
/*   Updated: 2025/02/13 23:09:28 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Animal.hpp"
#include "include/Cat.hpp"
#include "include/Dog.hpp"
#include "include/WrongAnimal.hpp"
#include "include/WrongCat.hpp"

int main(void)
{
    int size = 8;
    Animal *array[size];
    for (int i = 0; i < size / 2; i++)
        array[i] = new Cat();
    for (int i = size / 2; i < size; i++)
        array[i] = new Dog();
    for (int i = 0; i < size; i++)
    {
        array[i]->makeSound();
        delete(array[i]);
    }
    Cat original;
    original.setBrainThought("I love milk\n", 0);
    
    Cat copy = original;
    std::cout << std::endl;
    std::cout << "Original thought: " << original.getBrainThought(0) << std::endl;
    std::cout << "Copy's thought: " << copy.getBrainThought(0) << std::endl;
    
    original.setBrainThought("I HATEEEE milk but I love sardines\n", 0);
    
    std::cout << "Original thought: " << original.getBrainThought(0) << std::endl;
    std::cout << "Copy's thought: " << copy.getBrainThought(0) << std::endl;
}