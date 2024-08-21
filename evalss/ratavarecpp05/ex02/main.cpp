#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	try
	{
		// PresidentialPardonForm

		// PresidentialPardonForm doc1("Malandro");
        // Bureaucrat tim("Tim", 1);
        // tim.signForm(doc1);
        // tim.executeForm(doc1);
		// // PresidentialPardonForm doc2(doc1);
		// // tim.signForm(doc2);
		// PresidentialPardonForm doc3("Joao");
		// std::cout << doc3;
		// Bureaucrat pedro("Pedro", 135);
		// // pedro.signForm(doc3);
		// tim.executeForm(doc3);

		// ShrubberyCreationForm

		// ShrubberyCreationForm doc4("tree");
		// Bureaucrat christian("Christian", 136);
		// std::cout << doc4;
		// christian.signForm(doc4);
		// christian.executeForm(doc4);
		// ShrubberyCreationForm doc5("tree2");
		// Bureaucrat manel("Manel", 138);
		// manel.signForm(doc5);
		// manel.executeForm(doc5);

		// RobotomyRequestForm

		// RobotomyRequestForm doc5("Malandro");
		// Bureaucrat alexander("Alexander", 140);
		// alexander.signForm(doc5);
		// alexander.executeForm(doc5);

	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
}