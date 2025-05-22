/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 09:50:23 by yohan             #+#    #+#             */
/*   Updated: 2025/02/13 23:00:53 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"

Animal::Animal() : type("Undefined Animal")
{
    std::cout << "Default constructor called\n";
}

Animal::Animal(std::string type) : type(type)
{
    std::cout << "Constructor called: " << type << " created\n";
}

Animal &Animal::operator=(const Animal &other)
{
    if (this != &other)
        this->type = other.type;
    std::cout << type << " Copy assignment operator called\n"; 
    return (*this);
}

Animal::Animal(const Animal &copy)
{
    *this = copy;

    std::cout << type << " Copy assignment called\n"; 
}

Animal::~Animal()
{
    std::cout << "Animal of type: <" << type << "> destroyed\n"; 
}

void   Animal::makeSound() const
{
    std::cout << "Animal Noises...\n";
}