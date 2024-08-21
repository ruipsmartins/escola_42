/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifreire- <ifreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 03:20:20 by ifreire-          #+#    #+#             */
/*   Updated: 2024/01/29 07:47:33 by ifreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AMateria.hpp"
#include "../includes/ICharacter.hpp"

AMateria::AMateria(const std::string& type) : _type(type)
{
	std::cout << "+AMateria Default Constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& materia)
{
	std::cout << "+AMateria Copy Constructor called" << std::endl;
	*this = materia;
}

AMateria& AMateria::operator=(const AMateria& materia)
{
	std::cout << "+AMateria Assignment Constructor called" << std::endl;
	this->_type = materia._type;
	return (*this);
}

AMateria::~AMateria()
{
	std::cout << "-AMateria Destructor Constructor called" << std::endl;
}

const std::string& AMateria::getType() const
{
	return (this->_type);
}

