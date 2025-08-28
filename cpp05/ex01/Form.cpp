#include "Form.hpp"
#include "Bureaucrat.hpp"

//Constructor

Form::Form(const std::string& n, int gSign, int gExec)
	: name(n), isSigned(false), gradeToSign(gSign), gradeToExecute(gExec) {
	if (gSign < 1 || gExec < 1)
		throw GradeTooHighException();
	if (gSign > 150 || gExec > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& other)
	:	name(other.name),
		isSigned(other.isSigned),
		gradeToSign(other.gradeToSign),
		gradeToExecute(other.gradeToExecute) {}


