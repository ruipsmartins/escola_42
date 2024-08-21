#include "AForm.hpp"

AForm::AForm() : name("Default"), isSigned(false), signGrade(1), executeGrade(1) {}

AForm::~AForm() {}

AForm::AForm(const std::string name, int signGrade, int executeGrade) :
name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade) {
	if (signGrade < 1 || executeGrade < 1)
		throw AForm::GradeTooHighException();
	else if (signGrade > 150 || executeGrade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& copy) : signGrade(copy.signGrade), executeGrade(copy.executeGrade) {
	*this = copy;
}

AForm& AForm::operator=(const AForm& copy) {
	if (this != &copy) {
		const_cast<int&>(this->signGrade) = copy.signGrade;
		const_cast<int&>(this->executeGrade) = copy.executeGrade;
		const_cast<std::string&>(this->name) = copy.name;
		this->isSigned = copy.isSigned;
	}
	return (*this);
}

void AForm::beSigned(Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > this->signGrade)
		throw AForm::GradeTooLowException();
	if (this->isSigned == true)
		throw AForm::AFormIsAlreadySigned();
	this->isSigned = true;
}

std::string AForm::getName(void) const {return this->name;}

int AForm::getSignGrade(void) const {return this->signGrade;}

int AForm::getExecuteGrade(void) const {return this->executeGrade;}

bool AForm::getIsSigned(void) const {return this->isSigned;}

void AForm::canBeExecuted(const Bureaucrat & executor) const {
	if (this->isSigned == false)
		throw AForm::AFormIsNotSigned();
	if (executor.getGrade() > this->executeGrade)
		throw AForm::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const AForm& obj) {
	os << "Form: " << obj.getName() << std::endl 
		<< "Signed status: " << obj.getIsSigned() << std::endl
		<< "Required signing grade: " << obj.getSignGrade() << std::endl
		<< "Required executing grade: " << obj.getExecuteGrade() << std::endl;
	return os;
}
