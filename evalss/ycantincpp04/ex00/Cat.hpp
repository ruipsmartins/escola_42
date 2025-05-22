/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 20:28:43 by yohan             #+#    #+#             */
/*   Updated: 2025/02/11 14:52:23 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
#define CAT_H
#include "Animal.hpp"

class Cat : public Animal
{
    public:
    Cat();
    Cat(const Cat &copy);
    Cat& operator=(const Cat &other);
    ~Cat();
    void   makeSound() const;
};

#endif