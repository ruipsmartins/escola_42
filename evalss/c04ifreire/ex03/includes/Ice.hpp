/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifreire- <ifreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 03:20:37 by ifreire-          #+#    #+#             */
/*   Updated: 2024/01/29 07:53:20 by ifreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include <string>
#include <iostream>

class Ice: public AMateria
{
public:
	Ice();
	Ice(const Ice& ice);
	~Ice();
	Ice& operator=(const Ice& ice);
	Ice* clone() const;
	void use(ICharacter& target);
};

#endif
