/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 09:47:30 by yohan             #+#    #+#             */
/*   Updated: 2025/02/13 23:17:38 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>

class AAnimal
{
    protected:
    std::string type;
    public:
    AAnimal();
    AAnimal(std::string type);
    AAnimal(const AAnimal &copy); // copy existing animal to new animal
    AAnimal &operator=(const AAnimal &other); //copy existing animal to existing animal
    virtual void makeSound() const = 0;
    virtual ~AAnimal();
    virtual void    setBrainThought(std::string thought, int thoughtNum = -1) = 0;
    virtual std::string    getBrainThought(int thoughtNum) = 0;
};

#endif
