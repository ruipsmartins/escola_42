/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifreire- <ifreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 03:19:42 by ifreire-          #+#    #+#             */
/*   Updated: 2024/01/29 09:22:26 by ifreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MateriaSource.hpp"
#include <string>
#include <cstddef>
#include <iostream>

MateriaSource::MateriaSource() : _learnt()
{
	std::cout << "+MateriaSource Default Constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& materiaSource) : IMateriaSource(materiaSource), _learnt()
{
	std::cout << "+MateriaSource Copy Constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (materiaSource._learnt[i])
			this->_learnt[i] = materiaSource._learnt[i];
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& materiaSource)
{
	std::cout << "+MateriaSource Assignment Constructor called" << std::endl;
	if (this != &materiaSource) 
	{
		for (int i = 0; i < 4; ++i) 
		{
            if (materiaSource._learnt[i] != NULL) 
                this->_learnt[i] = materiaSource._learnt[i]->clone();
			else
                this->_learnt[i] = NULL;
        }
    }
	return (*this);
}

MateriaSource::~MateriaSource()
{
	std::cout << "-MateriaSource Destructor Constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_learnt[i])
			delete this->_learnt[i];
	}
}

void MateriaSource::learnMateria(AMateria* materia)
{
	for (int i = 0; i < 4; i++)
	{
		if (materia && this->_learnt[i] == NULL)
		{
			if (this->learnSlot(materia))
				this->_learnt[i] = materia;
			else
				this->_learnt[i] = materia;
			return ;
		}
	}
	if (materia)
		std::cout << "Error, Cannot learn materia" << std::endl;
	if (!this->learnSlot(materia))
		delete materia;
}

AMateria* MateriaSource::createMateria(const std::string& type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_learnt[i] && this->_learnt[i]->getType() == type)
			return (this->_learnt[i]->clone());
	}
	std::cout << "Error, Materia is invalid" << std::endl;
	return (0);
}

int MateriaSource::learnSlot(AMateria *materia)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_learnt[i] == materia)
			return (1);
	}
	return (0);
}