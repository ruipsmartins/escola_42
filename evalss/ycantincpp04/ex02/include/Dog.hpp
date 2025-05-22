/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 20:23:59 by yohan             #+#    #+#             */
/*   Updated: 2025/02/13 23:13:36 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
#define DOG_H
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
    private:
    Brain *brain;
    public:
    Dog();
    Dog(const Dog &copy);
    Dog& operator=(const Dog &other);
    ~Dog();
    void   makeSound() const;
    void   setBrainThought(std::string thought, int thoughtNum = -1);
    std::string   getBrainThought(int thoughtNum);
};

#endif