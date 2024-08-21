/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifreire- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 20:25:57 by ifreire-          #+#    #+#             */
/*   Updated: 2023/06/30 20:25:59 by ifreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongCat.hpp"

WrongCat::WrongCat(void)
{
    type = "WrongCat";
    std::cout << getType() << " Default Constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const &src)
{
    std::cout << "WrongCat Copy constructor called" << std::endl;
    *this = src;
}

WrongCat &WrongCat::operator=(WrongCat const &rhs)
{
    std::cout << "WrongCat Assignment constructor called " << std::endl;
    if (this != &rhs)
    {
        WrongAnimal::operator=(rhs);
        type = rhs.type;
    }
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat Destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "Alien Meow Meow" << std::endl;
}
