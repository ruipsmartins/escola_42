/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruidos-s <ruidos-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 20:23:44 by ifreire-          #+#    #+#             */
/*   Updated: 2024/01/29 11:31:24 by ruidos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <iomanip>
#include <cstdlib>

//virtual functions to ensure that the correct function is called for an object, regardless of the reference type used to call the function.

class Animal
{
protected:
    std::string type;
public:
    Animal();
    Animal(Animal const &src);
    virtual ~Animal();
    Animal &operator=(Animal const &rhs);

    virtual void makeSound() const;
    std::string getType() const;
};

#endif
