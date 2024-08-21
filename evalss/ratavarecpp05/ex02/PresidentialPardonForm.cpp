#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() :
AForm("PresidentialPardonForm", 25, 5), target("default") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
AForm("PresidentialPardonForm", 25, 5), target(target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) : 
AForm(copy) {
	*this = copy;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& copy) {
	if (this != &copy) {
		const_cast<std::string&>(this->target) = copy.target;
	}
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) {
	this->canBeExecuted(executor);
	std::cout << "Informs that " << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}