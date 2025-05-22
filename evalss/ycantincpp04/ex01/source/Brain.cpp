/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 22:05:50 by yohan             #+#    #+#             */
/*   Updated: 2025/02/13 22:48:01 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain constructor called\n";
    for (int i = 0; i < 100; i++)
        thoughts[i] = "nothing";
}
Brain::Brain(const Brain &copy)
{
    std::cout << "Brain copy constructor called\n";
    *this = copy;
}
Brain &Brain::operator=(const Brain &other)
{
    if (this != &other)
    {
        for (int i = 0; i < 100; i++)
            this->thoughts[i] = other.thoughts[i];
        this->thoughtCounter = other.thoughtCounter;
    }
    std::cout << "Brain copy operator called\n";
    return (*this);
}

std::string Brain::getThought(int thoughtNum)
{
    if (thoughtNum >= 0 && thoughtNum < 100)
        return (thoughts[thoughtNum]);
    return ("Thought is beyond this brain's capacity\n");
}
void        Brain::setThought(std::string thought, int thoughtNum)
{
    if (thoughtNum == -1)
    {
        if (thoughtCounter == 99) // circular memory
            thoughtCounter = 0;
        thoughts[thoughtCounter] = thought;
        thoughtCounter++;
    }
    else
        if (thoughtNum >= 0 && thoughtNum < 100)
            thoughts[thoughtNum] = thought;
        else
            std::cout << "Thought is beyond this brain's capacity\n";
}
Brain::~Brain()
{
    std::cout << "Brain destroyed\n";
}