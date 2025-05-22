/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 20:27:21 by yohan             #+#    #+#             */
/*   Updated: 2025/02/13 22:47:48 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"


Dog::Dog() : Animal(), brain(new Brain())
{
    std::cout << "Dog default constructor called\n";
    type = "Dog";
};

Dog::Dog(const Dog &copy) : Animal(copy)
{
    std::cout << "Dog copy constructor called\n";
    this->type = copy.type;
};

Dog &Dog::operator=(const Dog &other)
{
    if (this != &other)
        Animal::operator=(other);
    std::cout << "Dog copy operator called\n";
    return (*this);
}

void   Dog::makeSound() const
{
    std::cout << "woof woof!!!\n";    
}

Dog::~Dog()
{
    delete(brain);
    std::cout << "Dog destroyed\n";
}

void   Dog::setBrainThought(std::string thought, int thoughtNum)
{
    brain->setThought(thought, thoughtNum);
}
std::string   Dog::getBrainThought(int thoughtNum)
{
    return (brain->getThought(thoughtNum));
}