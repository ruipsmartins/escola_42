#include "Form.hpp"

Form::Form() : name("Default"), isSigned(false), signGrade(1), executeGrade(1) {}

Form::~Form() {}

Form::Form(const std::string name, int signGrade, int executeGrade) :
name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade) {
	if (signGrade < 1 || executeGrade < 1)
		throw Form::GradeTooHighException();
	else if (signGrade > 150 || executeGrade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& copy) : signGrade(copy.signGrade), executeGrade(copy.executeGrade) {
	*this = copy;
}

Form& Form::operator=(const Form& copy) {
	if (this != &copy) {
		const_cast<int&>(this->signGrade) = copy.signGrade;
		const_cast<int&>(this->executeGrade) = copy.executeGrade;
		const_cast<std::string&>(this->name) = copy.name;
		this->isSigned = copy.isSigned;
	}
	return (*this);
}

void Form::beSigned(Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > this->signGrade)
		throw Form::GradeTooLowException();
	if (this->isSigned == true)
		throw Form::FormIsAlreadySigned();
	this->isSigned = true;
}

std::string Form::getName(void) const {return this->name;}

int Form::getSignGrade(void) const {return this->signGrade;}

int Form::getExecuteGrade(void) const {return this->executeGrade;}

bool Form::getIsSigned(void) const {return this->isSigned;}

std::ostream& operator<<(std::ostream& os, const Form& obj) {
	os << "Form: " << obj.getName() << std::endl 
		<< "Signed status: " << obj.getIsSigned() << std::endl
		<< "Required signing grade: " << obj.getSignGrade() << std::endl
		<< "Required executing grade: " << obj.getExecuteGrade() << std::endl;
	return os;
}
