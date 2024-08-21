#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	const std::string target;
	PresidentialPardonForm();

public:
	PresidentialPardonForm(std::string target);
	~PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm& copy);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& copy);

	void execute(Bureaucrat const & executor);
};
