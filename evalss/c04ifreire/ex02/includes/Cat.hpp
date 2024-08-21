/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifreire- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 20:30:18 by ifreire-          #+#    #+#             */
/*   Updated: 2023/06/30 20:30:19 by ifreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "../includes/Animal.hpp"
#include "../includes/Brain.hpp"

//virtual functions to ensure that the correct function is called for an object, regardless of the reference type used to call the function.

class Cat : public Animal
{
private:
    Brain *brain;
public:
    Cat();
    Cat(Cat const &src);
    virtual ~Cat();
    Cat &operator=(Cat const &rhs);

    virtual void ideaN(int i) const;
    virtual void idea(int i, std::string str) const;
    virtual void makeSound() const;
};

#endif
