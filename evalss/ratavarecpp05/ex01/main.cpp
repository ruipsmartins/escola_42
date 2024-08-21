#include "Bureaucrat.hpp"

int main()
{
	try
	{
		// Form signing

		Bureaucrat joao("joao", 10);
		Form form1("Toddlers kidnapping permission", 15, 1);
		std::cout << form1;
		joao.signForm(form1);
		std::cout << form1;

		// Copy constructor and signing exception

		Bureaucrat cloneJoao(joao);
		Form form2(form1);
		for (int i = 0; i < 10; i++)
			cloneJoao.decrementGrade();
		cloneJoao.signForm(form2);

		// Signing an already signed form

		Bureaucrat antonio("antonio", 1);
		antonio.signForm(form1);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
}