/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrunho- <tgrunho-@student.42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 11:15:39 by tgrunho-          #+#    #+#             */
/*   Updated: 2025/01/19 09:05:58 by tgrunho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <PhoneBook.hpp>


int is_number(const std::string num) {
	for (size_t i = 0; i < num.length(); i++)
		if (!isdigit(num[i]))
			return (0);
	return (1);
}

	PhoneBook::PhoneBook(void) : contactcount(0) {}

	PhoneBook::~PhoneBook(void) {std::cout << "Destruction PhoneBook" << std::endl;};
	

	void PhoneBook::ADDContact(void)
	{
		if (contactcount >= 8) 
		{
			for (int i = 0; i < 7; i++)
				contacts[i] = contacts[i + 1];
			contactcount = 7;
		}
		contacts[contactcount].ADDContact();
		contactcount++;
		std::cout << "Contact added successfully!:D" << std::endl;
	}
			
	void PhoneBook::SEARCHContact(void) const
	{
		int index;
		std::string input;

		std::cout << "|     index|first name| last name|  nickname|" << std::endl;
		
		for (int i = 0; i < 8; i++) 
		{
			std::cout << "|";
			std::cout << std::setw(10) << i + 1 << "|";
			std::cout << std::setw(10) << contacts[i].get_first_name9() << "|";
			std::cout << std::setw(10) << contacts[i].get_last_name9() << "|";
			std::cout << std::setw(10) << contacts[i].get_nickname9() << "|" << std::endl;
		}

		std::cout << std::endl;

		while (true)
		{
			std::cout << "Enter contact index [1-8] or type 'EXIT' to quit: ";
			std::getline(std::cin, input);

			if (std::cin.eof() || input == "EXIT")
			{ 
				std::cout << "Exiting..." << std::endl;
				break;
			}

			if (input.empty() || !is_number(input))
			{
				std::cout << "Invalid input. Please enter a number between 1 and 8 or 'exit'." << std::endl;
				continue;
			}
			std::stringstream temp;
			temp << input;
			temp >> index;
			if (index >= 1 && index <= 8) 
			{
				std::cout << "First Name: " << contacts[index - 1].get_firstname() << std::endl;
				std::cout << "Last Name: " << contacts[index - 1].get_lastname() << std::endl;
				std::cout << "Nickname: " << contacts[index - 1].get_nickname() << std::endl;
				std::cout << "Phone Number: " << contacts[index - 1].get_phone_number() << std::endl;
				std::cout << "Darkest Secret: " << contacts[index - 1].get_darkest_secret() << std::endl;
				std::cout << std::endl;
			}
			else
				std::cout << "Invalid index. Please enter a number between 1 and 8." << std::endl;
		}
	}
