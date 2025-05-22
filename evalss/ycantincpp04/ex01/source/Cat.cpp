/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 20:29:58 by yohan             #+#    #+#             */
/*   Updated: 2025/02/13 23:04:57 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"

Cat::Cat() : Animal(), brain(new Brain())
{
    std::cout << "Cat default constructor called\n";
    type = "Cat";
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
    std::cout << "Cat copy constructor called\n";
    this->type = copy.type;
    brain = new Brain(*copy.brain);
}

Cat &Cat::operator=(const Cat &other)
{
    if (this != &other)
    {
        Animal::operator=(other);
        delete (brain);
        brain = new Brain(*other.brain);
    }
    std::cout << "Cat copy operator called\n";
    return (*this);
}

void   Cat::makeSound() const
{
    std::cout << "Meow Meow\n";
}

Cat::~Cat()
{
    delete(brain);
    std::cout << "Cat destroyed\n";
}

void   Cat::setBrainThought(std::string thought, int thoughtNum)
{
    brain->setThought(thought, thoughtNum);
}
std::string   Cat::getBrainThought(int thoughtNum)
{
    return (brain->getThought(thoughtNum));
}