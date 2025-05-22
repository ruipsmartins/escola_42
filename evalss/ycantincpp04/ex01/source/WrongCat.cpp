/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:50:46 by yohan             #+#    #+#             */
/*   Updated: 2025/02/13 19:31:28 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    std::cout << "Default WrongCat constructor called\n";
    type = "Default WrongCat";
}
WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy)
{
    this->type = copy.type;
    std::cout << "WrongCat copy constructor called\n";
}
WrongCat &WrongCat::operator=(const WrongCat &other)
{
    if (this != &other)
        WrongAnimal::operator=(other);
    std::cout << "WrongCat copy operator called\n";
    return (*this);
}

void    WrongCat::makeSound() const
{
    std::cout << "elephant noises..\n";
}
WrongCat::~WrongCat()
{
    std::cout << "WrongCat destroyed\n";
}