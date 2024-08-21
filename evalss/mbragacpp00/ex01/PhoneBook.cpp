
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	// std::cout << "Contructor Called" << std::endl;
	return;
}

PhoneBook::~PhoneBook(void)
{
	// std::cout << "Destructor Called" << std::endl;
	return;
}

void	PhoneBook::add_cont(void)
{
	Contact new_cont;

	new_cont.add_new();
	// std::cout << new_cont.nbr_contacts << std::endl;
	if (new_cont.nbr_contacts > 8)
		_list[(new_cont.nbr_contacts % 8) - 1] = new_cont; 
	else
		_list[new_cont.nbr_contacts - 1] = new_cont;
}

void	PhoneBook::search_cont(void) const
{
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname" << "|" << std::endl; 
	for (int i = 0; i < 8; i++)
	{
		std::cout << std::setw(10) << (i + 1) << "|";
		std::cout << std::setw(10) << truncate(this->_list[i].get_fname()) << "|";
		std::cout << std::setw(10) << truncate(this->_list[i].get_lname()) << "|";
		std::cout << std::setw(10) << truncate(this->_list[i].get_nname()) << "|" << std::endl;
	}
	return;
}

void	PhoneBook::show_cont(void) const
{
	std::string	input;
	int			index;

	std::cout << std::endl << "Choose index to see:" << std::endl;
	std::getline(std::cin, input);
	if (std::cin.eof() == 1)
		exit(0);
	if (input.length() > 1 || !isdigit(input[0]))
	{
		std::cout << "Invalid index." << std::endl;
		return;
	}
	index = atoi(input.c_str());
	if (index < 9 && index > 0)
	{
		std::cout << "\nFirst Name: " << this->_list[index - 1].get_fname() << std::endl;
		std::cout << "Last Name: " << this->_list[index - 1].get_lname() << std::endl;
		std::cout << "Nickname: " << this->_list[index - 1].get_nname() << std::endl;
		std::cout << "Phone Number: " << this->_list[index - 1].get_nbr() << std::endl;
		std::cout << "Darkest Secret: " << this->_list[index - 1].get_secret() << std::endl;
	}
	else
		std::cout << "Invalid index." << std::endl;
	return;
}

std::string	PhoneBook::truncate(std::string str) const
{
	if (str.length() > 10)
	{
		str = str.substr(0, 9);
		str.push_back('.');
	}
	return (str);
}
