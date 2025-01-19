/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrunho- <tgrunho-@student.42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 11:15:14 by tgrunho-          #+#    #+#             */
/*   Updated: 2025/01/12 00:13:02 by tgrunho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <PhoneBook.hpp>

int main() 
{
	PhoneBook phonebook;
	std::string command;

	while (true)
	{
		
		std::cout << "Enter a command: ADD, SEARCH, EXIT " << std::endl;
		std::getline(std::cin, command);
		if (command == "EXIT" || std::cin.eof()) 
		{
			std::cout << "OFF" << std::endl;
			break;
		}
		else if (command == "ADD")
			phonebook.ADDContact();
		else if (command == "SEARCH")
			phonebook.SEARCHContact();
		else
			std::cout << "Invalid Command" << std::endl;
	}
	return 0;
}