/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 09:49:46 by yohan             #+#    #+#             */
/*   Updated: 2025/02/13 19:26:05 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H
#include <iostream>

class WrongAnimal
{
    protected:
    std::string type;
    
    public:
    WrongAnimal();
    WrongAnimal(const std::string type);
    WrongAnimal(const WrongAnimal &copy);
    WrongAnimal &operator=(const WrongAnimal &other);
    virtual void    makeSound() const;
    virtual ~WrongAnimal();
};

#endif