/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifreire- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 20:24:02 by ifreire-          #+#    #+#             */
/*   Updated: 2023/06/30 20:24:06 by ifreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "../includes/Animal.hpp"

//virtual functions to ensure that the correct function is called for an object, regardless of the reference type used to call the function.

class Dog : public Animal
{
public:
    Dog();
    Dog(Dog const &src);
    virtual ~Dog();
    Dog &operator=(Dog const &rhs);

    virtual void makeSound() const;
};

#endif
