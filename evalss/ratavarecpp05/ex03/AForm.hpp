#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string	name;
	bool				isSigned;
	const int			signGrade;
	const int			executeGrade;

	AForm();

public:
	virtual ~AForm();
	AForm(const std::string name, int signGrade, int executeGrade);
	AForm(const AForm& copy);
	AForm& operator=(const AForm& copy);

	void beSigned(Bureaucrat& bureaucrat);

	std::string getName(void) const;
	int getSignGrade(void) const;
	int getExecuteGrade(void) const;
	bool getIsSigned(void) const;

	void canBeExecuted(Bureaucrat const & executor) const;
	virtual void execute(Bureaucrat const & executor) = 0;

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
	class AFormIsAlreadySigned : public std::exception
	{
		public:
			const char* what() const throw() {
				return "Form is already signed";
			}
	};
	class AFormIsNotSigned : public std::exception
	{
		public:
			const char* what() const throw() {
				return "Form hasn't been signed";
			}
	};
};

std::ostream& operator<<(std::ostream& os, const AForm& obj);
