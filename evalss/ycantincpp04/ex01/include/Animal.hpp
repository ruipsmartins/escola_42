/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 09:47:30 by yohan             #+#    #+#             */
/*   Updated: 2025/02/11 14:54:11 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>

class Animal
{
    protected:
    std::string type;
    public:
    Animal();
    Animal(std::string type);
    Animal(const Animal &copy); // copy existing animal to new animal
    Animal &operator=(const Animal &other); //copy existing animal to existing animal
    virtual void makeSound() const;
    virtual ~Animal();
};

#endif
