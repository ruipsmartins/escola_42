/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifreire- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 20:25:51 by ifreire-          #+#    #+#             */
/*   Updated: 2023/06/30 20:25:52 by ifreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"

WrongAnimal::WrongAnimal(void) : type ("Alien")
{
    std::cout << getType() << " Default Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &src)
{
    std::cout << "Alien Copy constructor called" << std::endl;
    type = src.type;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &rhs)
{
    std::cout << "Alien Assignment constructor called " << std::endl;
    if (this != &rhs)
    {
        type = rhs.type;
    }
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << getType() << " Destructor called" << std::endl;
}


void WrongAnimal::makeSound() const
{
    std::cout << "Alien Noise" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
    return (type);
}
