
#include "Contact.hpp"

Contact::Contact(void)
{
	this->nbr_contacts++;
}

Contact::~Contact(void)
{
	return;
}

int	Contact::nbr_contacts = -8;

void	Contact::add_new(void)
{
	std::string	nbr;

	std::cout << "Input the contact's first name:" << std::endl;
	while(this->_first_name.empty())
	{	
		std::getline(std::cin, this->_first_name);
		if (std::cin.eof() == 1)
			exit(0);
		if (this->_first_name.empty())
			std::cout << "Field can't be empty. Please retry:" << std::endl;
	}
	std::cout << "Input the contact's last name:" << std::endl;
	while(this->_last_name.empty())
	{	
		std::getline(std::cin, this->_last_name);
		if (std::cin.eof() == 1)
			exit(0);
		if (this->_last_name.empty())
			std::cout << "Field can't be empty. Please retry:" << std::endl;
	}
	std::cout << "Input the contact's nickname:" << std::endl;
	while(this->_nickname.empty())
	{	
		std::getline(std::cin, this->_nickname);
		if (std::cin.eof() == 1)
			exit(0);
		if (this->_nickname.empty())
			std::cout << "Field can't be empty. Please retry:" << std::endl;
	}
	std::cout << "Input the contact's number:" << std::endl;
	while(this->_number.empty())
	{	
		std::getline(std::cin, nbr);
		if (std::cin.eof() == 1)
			exit(0);
		this->_number = check_nbr(nbr);
		if (this->_number.empty())
			std::cout << "Field can't be empty. Please retry:" << std::endl;
	}
	std::cout << "Input the contact's darkest secret:" << std::endl;
	while(this->_secret.empty())
	{	
		std::getline(std::cin, this->_secret);
		if (std::cin.eof() == 1)
			exit(0);
		if (this->_secret.empty())
			std::cout << "Field can't be empty. Please retry:" << std::endl;
	}
}

std::string	Contact::check_nbr(std::string nbr) const
{
	int	flag;

	flag = 0;
	for (int i = 0; i < nbr.length(); i++)
	{
		if (!isdigit(nbr[i]))
			flag = 1;
	}
	if (flag)
	{
		std::cout << "Only numeric characters are allowed." << std::endl;
		std::cout << "Please retry:" << std::endl;
		std::getline(std::cin, nbr);
		if (std::cin.eof() == 1)
			exit;
		nbr = check_nbr(nbr);
	}
	return(nbr);
}

std::string	Contact::get_fname(void) const
{
	return(this->_first_name);
}

std::string	Contact::get_lname(void) const
{
	return(this->_last_name);
}

std::string	Contact::get_nname(void) const
{
	return(this->_nickname);
}

std::string	Contact::get_nbr(void) const
{
	return(this->_number);
}

std::string	Contact::get_secret(void) const
{
	return(this->_secret);
}
