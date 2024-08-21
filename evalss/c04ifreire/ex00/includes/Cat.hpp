/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifreire- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 20:23:53 by ifreire-          #+#    #+#             */
/*   Updated: 2023/06/30 20:23:55 by ifreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "../includes/Animal.hpp"

//virtual functions to ensure that the correct function is called for an object, regardless of the reference type used to call the function.

class Cat : public Animal
{
public:
    Cat();
    Cat(Cat const &src);
    Cat &operator=(Cat const &rhs);
    virtual ~Cat();

    virtual void makeSound() const;
};

#endif
