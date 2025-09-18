#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"  // Necesario porque usaremos Bureaucrat en métodos

class Bureaucrat; // forward declaration (para evitar dependencias circulares)

class AForm {
private:
    const std::string name;
    bool isSigned;
    const int gradeToSign;
    const int gradeToExecute;

public:
    // Constructor / Destructor
    AForm(const std::string& name, int gradeToSign, int gradeToExecute);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();

    // Getters
    const std::string& getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    // Métodos
    void beSigned(const Bureaucrat& b);
    virtual void execute(Bureaucrat const & executor) const = 0; // ← método puro

    // Excepciones
    class GradeTooHighException : public std::exception {
        public:
            const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
        public:
            const char* what() const throw();
    };
    class FormNotSignedException : public std::exception {
        public:
            const char* what() const throw();
    };
};

// Sobrecarga de operador <<
std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif
