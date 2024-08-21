/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifreire- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 20:32:45 by ifreire-          #+#    #+#             */
/*   Updated: 2023/06/30 20:32:46 by ifreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"

Brain::Brain(void)
{
    std::cout << "Brain Default Constructor called" << std::endl;
}

void Brain::setidea(int index, const std::string &idea) 
{

    if (index >= 0 && index < 100) 
    {
        ideas[index] = idea;
        index++;
    }
}

std::string Brain::getidea(int index) const 
{
    if (index >= 0 && index < 100) 
    {
        return ideas[index];
    }
    return "";
}

Brain::Brain(Brain const &src)
{
    std::cout << "Brain Copy constructor called" << std::endl;
    *this = src;
}

Brain &Brain::operator=(Brain const &rhs)
{
    std::cout << "Brain Assignment constructor called " << std::endl;
    if (this != &rhs)
    {
        for (int i = 0; i < 100; i++)
        {
		    ideas[i] = rhs.ideas[i];
        }
    }
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain Destructor called" << std::endl;
}
