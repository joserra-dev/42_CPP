#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

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

Form& Form::operator=(const Form& other) {
	if (this != &other) {
		this->isSigned = other.isSigned;
		//name, gradeToSign y gradeToExecute son const -> no se reasignan
	}
	return *this;
}

Form::~Form() {}

//Getters
const std::string& Form::getName() const {return name; }
bool Form::getIsSigned() const { return isSigned; }
int Form::getGradeToSign() const { return gradeToSign; }
int Form::getGradeToExecute() const { return gradeToExecute; }

//Metodo
void Form::beSigned(const Bureaucrat& b){
	if(b.getGrade() > gradeToSign)
		throw GradeTooHighException();
	isSigned = true;
}

//Excepciones

const char* Form::GradeTooHighException::what() const throw() {
	return "Form grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Form grade is too low!";
}

//Sobrecarga

std::ostream& operator<<(std::ostream& os, const Form& f) {
	os << "Form \"" <<f.getName()
		<< "\", signed: " << (f.getIsSigned() ? "yes" : "no")
		<< ", grade to sign: " << f.getGradeToSign()
		<< ", grade to execute: " << f.getGradeToExecute();
	return os;
}


