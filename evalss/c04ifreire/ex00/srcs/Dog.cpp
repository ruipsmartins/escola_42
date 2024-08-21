/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifreire- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 20:25:38 by ifreire-          #+#    #+#             */
/*   Updated: 2023/06/30 20:25:40 by ifreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog(void)
{
    type = "Dog";
    std::cout << getType() << " Default Constructor called" << std::endl;
}

Dog::Dog(Dog const &src)
{
    std::cout << "Dog Copy constructor called" << std::endl;
    *this = src;
}

Dog &Dog::operator=(Dog const &rhs)
{
    std::cout << "Dog Assignment constructor called " << std::endl;
    if (this != &rhs)
    {
        Animal::operator=(rhs);
        type = rhs.type;
    }
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog Destructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Wuuf Wuuf" << std::endl;
}
