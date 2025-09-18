#ifndef BUREAUCRAT_HPP
#define	BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

class Bureaucrat {

private:
	const std::string name;
	int grade;

public:
	// Constructores y destructor
	Bureaucrat(const std::string& name, int grade); // Sirve para crear un objeto desde cero, inicializándolo con un nombre y un rango.
	Bureaucrat(const Bureaucrat& other);			// Se usa cuando quieres crear un nuevo objeto copiando otro ya existente.
	Bureaucrat& operator=(const Bureaucrat& other);	//Se usa cuando ya existe un objeto y quieres copiarle los valores de otro.
	~Bureaucrat();

	//Getters
	const std::string& getName() const;
	int getGrade() const;

	// Metodos
	void incrementGrade();
	void decrementGrade();

	// Excepciones personalizadas
	class GradeTooHighException : public std::exception {
		public: 
			const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
		public: 
			const char* what() const throw();
	};
};

// Sobrecarga del operador
std::ostream& operator <<(std::ostream& os, const Bureaucrat& b);

#endif