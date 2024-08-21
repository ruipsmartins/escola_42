/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifreire- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 20:24:16 by ifreire-          #+#    #+#             */
/*   Updated: 2023/06/30 20:24:18 by ifreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>
#include <iomanip>
#include <cstdlib>

class WrongAnimal
{
protected:
    std::string type;
public:
    WrongAnimal();
    WrongAnimal(WrongAnimal const &src);
     ~WrongAnimal();
    WrongAnimal &operator=(WrongAnimal const &rhs);

    void makeSound() const;
    std::string getType() const;
};

#endif
