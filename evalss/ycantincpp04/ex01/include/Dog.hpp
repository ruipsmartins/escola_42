/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 20:23:59 by yohan             #+#    #+#             */
/*   Updated: 2025/02/13 22:39:45 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
#define DOG_H
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
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