/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifreire- <ifreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 03:20:46 by ifreire-          #+#    #+#             */
/*   Updated: 2024/01/29 07:53:43 by ifreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include <iostream>

class ICharacter;

class AMateria
{
private:
	AMateria();
protected:
	std::string _type;
public:
	AMateria(const std::string& type);
	AMateria(const AMateria& materia);
	virtual ~AMateria();
	AMateria& operator=(const AMateria& materia);
	const std::string& getType() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter &target) = 0;
};

#endif
