/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifreire- <ifreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 03:20:08 by ifreire-          #+#    #+#             */
/*   Updated: 2024/01/29 08:52:16 by ifreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Character.hpp"
#include <iostream>

Character::Character(const std::string& name) : _name(name), _slot()
{
	std::cout << "+Character Default Constructor called" << std::endl;
}

Character::Character(const Character& character) : ICharacter(character), _slot()
{
	std::cout << "+Character Copy Constructor called" << std::endl;
	this->_name = character._name;
	for (int i = 0; i < 4; i++)
	{
		if (character._slot[i])
			this->_slot[i] = character._slot[i];
	}
}

Character& Character::operator=(const Character& character)
{
	std::cout << "+Character Assignment Constructor called" << std::endl;
	this->_name = character._name;
	return(*this);
}

Character::~Character()
{
	std::cout << "-Character Destructor Constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_slot[i])
			delete this->_slot[i];
	}
}

const std::string& Character::getName() const
{
	return (_name);
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (m && this->_slot[i] == NULL)
		{
			if (this->inInventory(m))
				this->_slot[i] = m->clone();
			else
				this->_slot[i] = m;
			return ;
		}
	}
	if (m)
		std::cout << "Error, cant equip materia" << std::endl;
	if (!this->inInventory(m))
		delete m;
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && this->_slot[idx])
	{
		this->_slot[idx] = NULL;
		std::cout << "Unequipped materia" << std::endl;
	}
	else
		std::cout << "Error, cant unequip materia" << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && this->_slot[idx])
		this->_slot[idx]->use(target);
	else
		std::cout << "Error, cant use materia" << std::endl;
}

int Character::inInventory(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_slot[i] == m)
			return (1);
	}
	return (0);
}

void Character::setName(std::string NewName)
{
	this->_name = NewName;
}