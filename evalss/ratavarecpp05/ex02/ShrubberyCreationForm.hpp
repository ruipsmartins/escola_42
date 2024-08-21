#pragma once

#include "AForm.hpp"
#include "fstream"

class ShrubberyCreationForm : public AForm
{
private:
	const std::string target;
	ShrubberyCreationForm();

public:
	ShrubberyCreationForm(std::string target);
	~ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm& copy);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& copy);

	void execute(Bureaucrat const & executor);
};
