/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 20:28:43 by yohan             #+#    #+#             */
/*   Updated: 2025/02/13 22:39:37 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
#define CAT_H
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    private:
    Brain *brain;
    public:
    Cat();
    Cat(const Cat &copy);
    Cat& operator=(const Cat &other);
    ~Cat();
    void   makeSound() const;
    void   setBrainThought(std::string thought, int thoughtNum = -1);
    std::string   getBrainThought(int thoughtNum);
};

#endif