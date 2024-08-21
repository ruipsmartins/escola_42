/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifreire- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 20:30:23 by ifreire-          #+#    #+#             */
/*   Updated: 2023/06/30 20:30:25 by ifreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "../includes/Animal.hpp"
#include "../includes/Brain.hpp"

//virtual functions to ensure that the correct function is called for an object, regardless of the reference type used to call the function.

class Dog : public Animal
{
private:
    Brain *brain;
public:
    Dog();
    Dog(Dog const &src);
    virtual ~Dog();
    Dog &operator=(Dog const &rhs);

    virtual void ideaN(int i) const;
    virtual void idea(int i, std::string str) const;
    virtual void makeSound() const;
};

#endif
