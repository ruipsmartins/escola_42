/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:33:18 by yohan             #+#    #+#             */
/*   Updated: 2025/02/13 22:16:43 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
#define BRAIN_H
#include <iostream>

class Brain
{
    protected:
    std::string thoughts[100];
    int         thoughtCounter;
    public:
    Brain();
    Brain(const Brain &copy);
    Brain &operator=(const Brain &other);
    std::string getThought(int thoughtNum);
    void        setThought(std::string thought, int thoughtNum = -1);
    ~Brain();
};

#endif