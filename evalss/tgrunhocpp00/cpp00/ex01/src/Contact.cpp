/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrunho- <tgrunho-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:42:45 by tgrunho-          #+#    #+#             */
/*   Updated: 2024/11/12 14:49:58 by tgrunho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Contact.hpp>

Contact::Contact(void) : firstname(""), lastname(""), nickname(""),
						 phone_number(""), darkest_secret("") {}

Contact::~Contact(void) 
{
	std::cout << "Destruction Contact " << firstname << std::endl;
}

std::string Contact::get_firstname(void) const
{
	return firstname;
}
std::string Contact::get_lastname(void) const 
{
	return lastname;
}
std::string Contact::get_nickname(void) const 
{
	return nickname;
}
std::string Contact::get_phone_number(void) const
{
	return phone_number;
}
std::string Contact::get_darkest_secret(void) const 
{
	return darkest_secret;
}
std::string Contact::get_first_name9(void) const 
{
	if (firstname.length() > 10)
		return (firstname.substr(0, 9) + ".");
	else
		return firstname;
}
std::string Contact::get_last_name9(void) const 
{
	if (lastname.length() > 10)
		return (lastname.substr(0, 9) + ".");
	else
		return lastname;
}
std::string Contact::get_nickname9(void) const 
{
	if (nickname.length() > 10)
		return (nickname.substr(0, 9) + ".");
	else
		return nickname;
}

void Contact::get_input(std::string *input, const std::string message)
{
	while (input->empty()) {         
		std::cout << message << ": ";
		std::getline(std::cin, *input);
		if (std::cin.eof())
		{   
			std::cout << "OFF" << std::endl;
			break;
		}
	}
}

void Contact::ADDContact(void) {
	firstname.clear();
	get_input(&firstname, "First Name");
	lastname.clear();
	get_input(&lastname, "Last Name");
	nickname.clear();
	get_input(&nickname, "Nickname");
	phone_number.clear();
	get_input(&phone_number, "Phone Number");
	darkest_secret.clear();
	get_input(&darkest_secret, "Darkest Secret");
}
