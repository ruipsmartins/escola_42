
#include "PhoneBook.hpp"
#include <string>

int main(void)
{
	std::string	input;
	PhoneBook	pb;

	std::cout << "- Welcome to your Phonebook -" << std::endl;
	while (1)
	{
		std::cout << std::endl << "Please type an option:\n ADD | SEARCH | EXIT" << std::endl;
		std::getline(std::cin, input);
		if (std::cin.eof() == 1 || input == "EXIT")
			break;
		if (input == "ADD")
			pb.add_cont();
		else if (input == "SEARCH")
		{
			pb.search_cont();
			pb.show_cont();
		}
		else
			std::cout << "Invalid option." << std::endl;
		std::cin.clear();
	}
	return (0);
}
