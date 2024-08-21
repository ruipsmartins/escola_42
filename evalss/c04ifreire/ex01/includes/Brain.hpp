/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifreire- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 20:30:13 by ifreire-          #+#    #+#             */
/*   Updated: 2023/06/30 20:30:14 by ifreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <iomanip>
#include <cstdlib>

class Brain
{
private:
    std::string ideas[100];
    // int i;
public:
    Brain();
    Brain(Brain const &src);
    ~Brain();
    Brain &operator=(Brain const &rhs);

    void setidea(int index, const std::string &idea);
    std::string getidea(int index) const;
};

#endif
