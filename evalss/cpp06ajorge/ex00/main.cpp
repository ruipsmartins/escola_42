/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:07:52 by ajorge-p          #+#    #+#             */
/*   Updated: 2025/03/06 12:45:29 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if(ac == 2)
	{
		const std::string s = av[1];

		ScalarConverter::convert(s);
	}
	else
		std::cerr << "Correct way: ./Scalar <value> !!" << std::endl;
}