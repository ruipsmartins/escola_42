/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifreire- <ifreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 03:20:05 by ifreire-          #+#    #+#             */
/*   Updated: 2024/01/29 08:49:37 by ifreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cure.hpp"
#include "../includes/ICharacter.hpp"
#include <iostream>

Cure::Cure(): AMateria("cure")
{
	std::cout << "+Cure Default Constructor called" << std::endl;
}

Cure::Cure(const Cure& cure): AMateria(cure)
{
	std::cout << "+Cure Copy Constructor called" << std::endl;
}

Cure& Cure::operator=(const Cure &cure)
{
	std::cout << "+Cure Assignment Constructor called" << std::endl;
	this->_type = cure._type;
	return (*this);
}

Cure::~Cure()
{
	std::cout << "-Cure Destructor Constructor called" << std::endl;
}

Cure* Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << " wounds *" << std::endl;
}
