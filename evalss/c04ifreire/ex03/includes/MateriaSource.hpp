/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifreire- <ifreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 03:20:26 by ifreire-          #+#    #+#             */
/*   Updated: 2024/01/29 09:22:22 by ifreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MATERIA_SOURCE_HPP
#define MATERIA_SOURCE_HPP

#include "IMateriaSource.hpp"
#include <string>
#include <iostream>

class MateriaSource: public IMateriaSource
{
private:
	AMateria* _learnt[4];
public:
	MateriaSource();
	MateriaSource(const MateriaSource& materiaSource);
	~MateriaSource();
	MateriaSource& operator=(const MateriaSource& materiaSource);
	void learnMateria(AMateria* materia);
	AMateria* createMateria(const std::string& type);
	int learnSlot(AMateria *materia);
};

#endif
