#include "RobotomyRequestForm.hpp"
#include <iostream>

// Constructor
RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("RobotomyRequestForm", 72, 45), target(target) {}

// Copia
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other), target(other.target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm() {}

// Método execute
void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    if (!getIsSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw GradeTooLowException();

    std::cout << "BZZZZZZZT... DRRRRRRRRRR... (taladro sonando)" << std::endl;

    // inicializamos la semilla (solo la primera vez)
    static bool seeded = false;
    if (!seeded) {
        std::srand(std::time(NULL));
        seeded = true;
    }

    if (std::rand() % 2) {
        std::cout << target << " has been robotomized successfully 🤖✅" << std::endl;
    } else {
        std::cout << "Robotomy failed on " << target << " ❌" << std::endl;
    }

    std::cout << executor.getName() << " executed " << getName() << std::endl;
}
