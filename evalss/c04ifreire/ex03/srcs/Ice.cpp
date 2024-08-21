/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifreire- <ifreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 03:19:55 by ifreire-          #+#    #+#             */
/*   Updated: 2024/01/29 08:09:14 by ifreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Ice.hpp"
#include "../includes/ICharacter.hpp"
#include <iostream>

Ice::Ice(): AMateria("ice")
{
	std::cout << "+Ice Default Constructor called" << std::endl;
}

Ice::Ice(const Ice &ice): AMateria(ice)
{
	std::cout << "+Ice Copy Constructor called" << std::endl;
}

Ice& Ice::operator=(const Ice &ice)
{
	std::cout << "+Ice Assignment Constructor called" << std::endl;
	this->_type = ice._type;
	return (*this);
}

Ice::~Ice()
{
	std::cout << "-Ice Destructor Constructor called" << std::endl;
}

Ice* Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
