#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat joao("joao", 10);
		std::cout << joao << std::endl;
		Bureaucrat antonio("antonio", 150);
		std::cout << antonio << std::endl;
		joao.incrementGrade();
		std::cout << joao << std::endl;
		Bureaucrat joao2(joao);
		std::cout << joao2 << std::endl;

		// Grade too low exception.

		antonio.decrementGrade();
		std::cout << antonio << std::endl;

		// Grade too high exception.
		for (int i = 9; i > -5; i--) {
			joao.incrementGrade();
			std::cout << joao << std::endl;
		}
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
}