/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 20:23:59 by yohan             #+#    #+#             */
/*   Updated: 2025/02/11 14:52:28 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
#define DOG_H
#include "Animal.hpp"

class Dog : public Animal
{
    public:
    Dog();
    Dog(const Dog &copy);
    Dog& operator=(const Dog &other);
    ~Dog();
    void   makeSound() const;
};

#endif