#pragma once

#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm
{
private:
	const std::string target;
	RobotomyRequestForm();

public:
	RobotomyRequestForm(std::string target);
	~RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm& copy);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& copy);

	void execute(Bureaucrat const & executor);
};
