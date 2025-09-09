#include "Bureaucrat.hpp"
#include "Form.hpp"

void Bureaucrat::signForm(Form& f){
	try
	{
		f.beSigned(*this);
		std::cout << name << "signed" << f.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << name << " couldn't sign " << f.getName()
		<< "because " << e.what() << std::endl;
	}
	
}

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
        this->grade = other.grade;
        // 'name' es const, no se reasigna
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {}

// Getters
const std::string& Bureaucrat::getName() const { return name; }
int Bureaucrat::getGrade() const { return grade; }

// Métodos
void Bureaucrat::incrementGrade() {
    if (grade <= 1)
        throw GradeTooHighException();
    grade--;
}

void Bureaucrat::decrementGrade() {
    if (grade >= 150)
        throw GradeTooLowException();
    grade++;
}

// Excepciones
const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

// Sobrecarga <<
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}
