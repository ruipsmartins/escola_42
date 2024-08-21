/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifreire- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 20:25:33 by ifreire-          #+#    #+#             */
/*   Updated: 2023/06/30 20:25:34 by ifreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat(void)
{
    type = "Cat";
    std::cout << getType() << " Default Constructor called" << std::endl;
}

Cat::Cat(Cat const &src)
{
    std::cout << "Cat Copy constructor called" << std::endl;
    *this = src;
}

Cat &Cat::operator=(Cat const &rhs)
{
    std::cout << "Cat Assignment constructor called " << std::endl;
    if (this != &rhs)
    {
        Animal::operator=(rhs);
        type = rhs.type;
    }
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat Destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Meow Meow" << std::endl;
}
