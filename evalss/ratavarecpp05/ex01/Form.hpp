#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string	name;
	bool				isSigned;
	const int			signGrade;
	const int			executeGrade;

	Form();

public:
	~Form();
	Form(const std::string name, int signGrade, int executeGrade);
	Form(const Form& copy);
	Form& operator=(const Form& copy);

	void beSigned(Bureaucrat& bureaucrat);

	std::string getName(void) const;
	int getSignGrade(void) const;
	int getExecuteGrade(void) const;
	bool getIsSigned(void) const;

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
	class FormIsAlreadySigned : public std::exception
	{
		public:
			const char* what() const throw() {
				return "Form is already signed";
			}
	};
};

std::ostream& operator<<(std::ostream& os, const Form& obj);
