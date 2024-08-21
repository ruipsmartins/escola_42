#pragma once

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
private:
    std::string formNames[3];
public:
	Intern();
	Intern(const Intern& copy);
	Intern& operator=(const Intern& copy);
	~Intern();

	AForm* makeForm(std::string name, std::string target);

	class InexistentForm : public std::exception
	{
	public:
		const char* what() const throw() {
			return "Form does not exist";
		}
	};
};
