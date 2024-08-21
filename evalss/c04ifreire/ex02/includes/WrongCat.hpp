/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifreire- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 20:24:24 by ifreire-          #+#    #+#             */
/*   Updated: 2023/06/30 20:24:25 by ifreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "../includes/WrongAnimal.hpp"

//virtual functions to ensure that the correct function is called for an object, regardless of the reference type used to call the function.

class WrongCat : public WrongAnimal
{
public:
    WrongCat();
    WrongCat(WrongCat const &src);
    ~WrongCat();
    WrongCat &operator=(WrongCat const &rhs);

    void makeSound() const;
};

#endif
