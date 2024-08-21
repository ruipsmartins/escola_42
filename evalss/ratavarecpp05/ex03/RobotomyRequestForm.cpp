#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() :
AForm("RobotomyRequestForm", 72, 45), target("default") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
AForm("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) : 
AForm(copy) {
	*this = copy;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy) {
	if (this != &copy) {
		const_cast<std::string&>(this->target) = copy.target;
	}
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) {
	this->canBeExecuted(executor);
	srand(time(0));
	std::cout << "*drilling noises* "; 
	if (rand() % 2 == 0)
		std::cout << this->target << " has been robotomized" << std::endl;
	else
		std::cout << this->target << "'s robotomy failed" << std::endl;
}