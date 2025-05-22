/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 09:56:11 by yohan             #+#    #+#             */
/*   Updated: 2025/02/13 19:16:50 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("default wrong animal")
{
    std::cout << "Wrong Animal default constructor called\n";
}

WrongAnimal::WrongAnimal(const std::string type) : type(type)
{
    std::cout << "Wrong Animal constructor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
    this->type = copy.type;
    
    std::cout << "WrongAnimal copy constructor called\n";
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
    if (this != &other)
        this->type = other.type;
    std::cout << "WrongAnimal copy operator called\n";
    return (*this);
}

void    WrongAnimal::makeSound() const
{
    std::cout << "undisclosed WrongAnimal noises\n";
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "Wrong Animal destroyed\n";
}