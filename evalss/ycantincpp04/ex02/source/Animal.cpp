/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 09:50:23 by yohan             #+#    #+#             */
/*   Updated: 2025/02/13 23:14:19 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"

AAnimal::AAnimal() : type("Undefined Animal")
{
    std::cout << "Default constructor called\n";
}

AAnimal::AAnimal(std::string type) : type(type)
{
    std::cout << "Constructor called: " << type << " created\n";
}

AAnimal &AAnimal::operator=(const AAnimal &other)
{
    if (this != &other)
        this->type = other.type;
    std::cout << type << " Copy assignment operator called\n"; 
    return (*this);
}

AAnimal::AAnimal(const AAnimal &copy)
{
    *this = copy;

    std::cout << type << " Copy assignment called\n"; 
}

AAnimal::~AAnimal()
{
    std::cout << "Animal of type: <" << type << "> destroyed\n"; 
}

void   AAnimal::makeSound() const
{
    std::cout << "Animal Noises...\n";
}