#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>  // rand, srand
#include <ctime>    // time (para inicializar la semilla)

class RobotomyRequestForm : public AForm {
private:
    std::string target;

public:
    // Constructores y destructor
    RobotomyRequestForm(const std::string& target);
    RobotomyRequestForm(const RobotomyRequestForm& other);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
    ~RobotomyRequestForm();

    // Método específico
    void execute(Bureaucrat const & executor) const;
};

#endif
