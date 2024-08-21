/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifreire- <ifreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 20:32:56 by ifreire-          #+#    #+#             */
/*   Updated: 2023/07/20 21:40:27 by ifreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"
#include "../includes/Brain.hpp"

Dog::Dog(void)
{
    type = "Dog";
    std::cout << getType() << " Default Constructor called" << std::endl;
    brain = new Brain();
}

Dog::Dog(Dog const &src)
{
    std::cout << "Dog Copy constructor called" << std::endl;
    brain = new Brain();
    *this = src;
}

Dog &Dog::operator=(Dog const &rhs)
{
    std::cout << "Dog Assignment constructor called " << std::endl;
    if (this != &rhs)
    {
        Animal::operator=(rhs);
        type =  rhs.type;
        delete brain;
        brain = new Brain(*rhs.brain);
    }
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog Destructor called" << std::endl;
    if (brain)
        delete brain;
}

void Dog::makeSound() const
{
    std::cout << "Wuuf Wuuf" << std::endl;
}

void Dog::idea(int i, std::string str) const
{
    brain->setidea(i, str);
    std::cout << brain->getidea(i) << std::endl;
}

void Dog::ideaN(int i) const
{
    std::cout << brain->getidea(i) << std::endl;
}
