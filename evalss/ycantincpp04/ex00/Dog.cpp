/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 20:27:21 by yohan             #+#    #+#             */
/*   Updated: 2025/02/13 17:08:52 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"


Dog::Dog() : Animal()
{
    std::cout << "Dog default constructor called\n";
    type = "Dog";
};

Dog::Dog(const Dog &copy) : Animal(copy)
{
    std::cout << "Dog copy constructor called\n";
    this->type = copy.type;
};

Dog &Dog::operator=(const Dog &other)
{
    if (this != &other)
        Animal::operator=(other);
    std::cout << "Dog copy operator called\n";
    return (*this);
}

void   Dog::makeSound() const
{
    std::cout << "woof woof!!!\n";    
}

Dog::~Dog()
{
    std::cout << "Dog destroyed\n";
}