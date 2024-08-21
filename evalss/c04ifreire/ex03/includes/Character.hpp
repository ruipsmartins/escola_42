/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifreire- <ifreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 03:20:43 by ifreire-          #+#    #+#             */
/*   Updated: 2024/01/29 07:53:24 by ifreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <string>
#include <iostream>

class Character: public ICharacter
{
private:
	std::string _name;
	AMateria* _slot[4];
public:
	Character(const std::string& name);
	Character(const Character& character);
	~Character();
	Character& operator=(const Character& character);
	const std::string& getName() const;
	virtual void equip(AMateria* m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter& target);
	int inInventory(AMateria *m);
	void setName(std::string NewName);
};

#endif
