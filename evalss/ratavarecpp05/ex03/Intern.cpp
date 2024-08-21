#include "Intern.hpp"

Intern::Intern() {
	formNames[0] = "ShrubberyCreationForm";
	formNames[1] = "RobotomyRequestForm";
	formNames[2] = "PresidentialPardonForm";
}

Intern::Intern(const Intern& copy) {
	*this = copy;
}

Intern& Intern::operator=(const Intern& copy) {
	if (this != &copy) {
	for (int i = 0; i < 3; i++)
		this->formNames[i] = copy.formNames[i];
	}
	return (*this);
}

Intern::~Intern() {}

AForm* createPresidentialPardonForm(std::string target) {
        return new PresidentialPardonForm(target);
    }

AForm* createRobotomyRequestForm(std::string target) {
        return new RobotomyRequestForm(target);
    }

AForm* createShrubberyCreationForm(std::string target) {
        return new ShrubberyCreationForm(target);
    }

static AForm *makePresident(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

static AForm *makeRobot(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

static AForm *makeShrubbery(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm* Intern::makeForm(std::string name, std::string target) {
	AForm *(*function[])(const std::string target) = {&makeShrubbery, &makeRobot, &makePresident};

	for (int i = 0; i < 3; i++) {
		if (name == this->formNames[i])	{
			std::cout << "Intern creates: " << this->formNames[i] << std::endl;
			return ((*function[i])(target));
		}
	}
	std::cout << "Intern couldn't create form, exception: ";
	throw Intern::InexistentForm();
}