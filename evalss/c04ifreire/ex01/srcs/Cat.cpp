/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifreire- <ifreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 20:32:51 by ifreire-          #+#    #+#             */
/*   Updated: 2023/06/30 21:45:14 by ifreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"
#include "../includes/Brain.hpp"

Cat::Cat(void)
{
    type = "Cat";
    std::cout << getType() << " Default Constructor called" << std::endl;
    brain = new Brain();
}

Cat::Cat(Cat const &src)
{
    std::cout << "Cat Copy constructor called" << std::endl;
    if (this != &src)
        *this = src;
}

Cat &Cat::operator=(Cat const &rhs)
{
    std::cout << "Cat Assignment constructor called " << std::endl;
    if (this != &rhs)
    {
        Animal::operator=(rhs);
        type = rhs.type;
        delete brain;
        brain = new Brain(*rhs.brain);
    }
    return *this;
}

Cat::~Cat()
{
    std::cout << getType() << " Destructor called" << std::endl;
    if (this->brain)
        delete brain;
}

void Cat::makeSound() const
{
    std::cout << "Meow Meow" << std::endl;
}

void Cat::idea(int i, std::string str) const
{
    brain->setidea(i, str);
    std::cout << brain->getidea(i) << std::endl;
}

void Cat::ideaN(int i) const
{
    std::cout << brain->getidea(i) << std::endl;
}
