#include "ShrubberyCreationForm.hpp"
#include <iostream>

// Constructor
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137), target(target) {}

// Copia
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), target(other.target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm() {}

// Método execute
void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    if (!getIsSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw GradeTooLowException();

    std::ofstream outFile((target + "_shrubbery").c_str());
    if (!outFile) {
        std::cerr << "Error: no se pudo abrir el archivo para escribir." << std::endl;
        return;
    }

    outFile << "       _-_" << std::endl;
    outFile << "    /~~   ~~\\" << std::endl;
    outFile << " /~~         ~~\\" << std::endl;
    outFile << "{               }" << std::endl;
    outFile << " \\  _-     -_  /" << std::endl;
    outFile << "   ~  \\\\ //  ~" << std::endl;
    outFile << "_- -   | | _- _" << std::endl;
    outFile << "  _ -  | |   -_" << std::endl;
    outFile << "      // \\\\" << std::endl;

    outFile.close();
    std::cout << executor.getName() << " executed " << getName() << std::endl;
}
