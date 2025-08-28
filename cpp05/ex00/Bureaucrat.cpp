#include "Bureaucrat.hpp"
#include <iostream>

// Constructor

Bureaucrat::Bureaucrat(const std::string& n, int g) : name(n), grade(g) {
	if (g < 1)
		throw GradeTooHighException();
	if (g > 150)
		throw GradeTooLowException();

}
Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) {
		this ->grade = other.grade;
		//'name' es const, no se reasigna
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {}

	//Getters
const std::string& Bureaucrat::getName() const { return name; }	
int Bureaucrat::getGrade() const {return grade; }

// Metodos
void Bureaucrat::incrementGrade() {
	if (grade <= 1)
		throw GradeTooHighException();
	grade--;
}

