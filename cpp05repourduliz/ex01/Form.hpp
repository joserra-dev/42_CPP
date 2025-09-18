#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat; //forward declaration

class Form{
	private:
		const std::string name;
		bool isSigned;
		const int gradeToSign;
		const int gradeToExecute;
	
	public:
	Form(const std::string& name, int gradeToSign, int gradeToExecute);
	Form (const Form& other);
	Form& operator=(const Form& other);
	~Form();

	//Getters
	const std::string& getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

	//Metodo
	void beSigned(const Bureaucrat& b);

	//Excepciones
	class GradeTooHighException : public std::exception {
		public:
		const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
		public:
		const char* what() const throw();
	};
};

//Sobrecarga
std::ostream& operator<<(std::ostream& os, const Form& f);

#endif