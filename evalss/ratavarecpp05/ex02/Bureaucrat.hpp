#pragma once

#include <iostream>
#include <stdexcept>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
private:
	const std::string	name;
	int 				grade;
	Bureaucrat();
public:
	Bureaucrat(const std::string name, int grade);
	Bureaucrat(const Bureaucrat& copy);
	~Bureaucrat();
	Bureaucrat& operator=(const Bureaucrat& copy);

	void signForm(AForm& form);
	void executeForm(AForm const & form);

	std::string getName(void) const;
	int getGrade(void) const;
	void incrementGrade(void);
	void decrementGrade(void);

	class GradeTooHighException : public std::exception
	{
	public:
		const char* what() const throw() {
			return "Grade too high!";
		}
	};
	class GradeTooLowException : public std::exception
	{
	public:
		const char* what() const throw() {
			return "Grade too low!";
		}
	};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);