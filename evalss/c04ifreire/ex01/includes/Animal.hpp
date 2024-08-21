/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifreire- <ifreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 20:30:05 by ifreire-          #+#    #+#             */
/*   Updated: 2023/06/30 22:03:28 by ifreire-         ###   ########.fr       */
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

    virtual void ideaN(int i) const;
    virtual void idea(int i, std::string str) const;
    virtual void makeSound() const;
    std::string getType() const;
    void setType(std::string types);
};

#endif
