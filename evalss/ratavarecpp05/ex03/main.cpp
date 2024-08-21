#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	AForm* doc1 = NULL;
	try
	{
		Intern johnny;
		doc1 = johnny.makeForm("RobotomyRequestfForm", "Malandro");
		Bureaucrat tim("Tim", 1);
		std::cout << tim << std::endl;
		tim.signForm(*doc1);
		tim.executeForm(*doc1);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	if (doc1)
		delete doc1;
}