/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifreire- <ifreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 03:20:40 by ifreire-          #+#    #+#             */
/*   Updated: 2024/01/29 07:53:22 by ifreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include <string>
#include <iostream>

class Cure: public AMateria
{
public:
	Cure();
	Cure(const Cure& cure);
	~Cure();
	Cure& operator=(const Cure& cure);
	Cure* clone() const;
	void use(ICharacter& target);
};

#endif

