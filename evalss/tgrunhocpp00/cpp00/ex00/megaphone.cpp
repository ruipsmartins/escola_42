/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrunho- <tgrunho-@student.42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:42:45 by tgrunho-          #+#    #+#             */
/*   Updated: 2025/01/19 08:58:37 by tgrunho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "megaphone.hpp"

int main(int argc, char **argv)
{
    int i;
    
    i = 0;
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }
    if (argc >= 2)
    {
        i = 1;
        while (i < argc)
        {
            int a = 0;
            while (argv[i][a])
            {
                argv[i][a] = toupper(argv[i][a]);
                std::cout << argv[i][a];
                a++;
            }
            i++;
        }
    }
    std::cout << std::endl;
    return 0;
}

