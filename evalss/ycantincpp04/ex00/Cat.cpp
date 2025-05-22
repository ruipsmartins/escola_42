/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 20:29:58 by yohan             #+#    #+#             */
/*   Updated: 2025/02/13 17:08:42 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
    std::cout << "Cat default constructor called\n";
    type = "Cat";
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
    std::cout << "Cat copy constructor called\n";
    this->type = copy.type;
}

Cat &Cat::operator=(const Cat &other)
{
    if (this != &other)
        Animal::operator=(other);
    std::cout << "Cat copy operator called\n";
    return (*this);
}

void   Cat::makeSound() const
{
    std::cout << "Meow Meow\n";
}

Cat::~Cat()
{
    std::cout << "Cat destroyed\n";
}