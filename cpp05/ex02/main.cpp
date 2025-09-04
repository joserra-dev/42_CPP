#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat high("Alice", 1);      // grade más alto
        Bureaucrat mid("Bob", 50);        // grade intermedio
        Bureaucrat low("Charlie", 150);   // grade más bajo

        std::cout << high << std::endl;
        std::cout << mid << std::endl;
        std::cout << low << std::endl;

        // Formularios con target
        ShrubberyCreationForm shrub("home");
        RobotomyRequestForm robo("Marvin");
        PresidentialPardonForm pardon("Arthur Dent");

        std::cout << "\n=== TEST SHRUBBERY ===" << std::endl;
        low.signForm(shrub);              // debería fallar (grade demasiado bajo)
        high.signForm(shrub);             // éxito
        low.executeForm(shrub);           // debería fallar
        high.executeForm(shrub);          // debería crear archivo con arbolito

        std::cout << "\n=== TEST ROBOTOMY ===" << std::endl;
        mid.signForm(robo);               // éxito
        mid.executeForm(robo);            // falla (grade demasiado bajo para ejecutar)
        high.executeForm(robo);           // éxito (50% chance)

        std::cout << "\n=== TEST PARDON ===" << std::endl;
        high.signForm(pardon);            // éxito
        mid.executeForm(pardon);          // debería fallar
        high.executeForm(pardon);         // éxito (perdón)

    } catch (std::exception& e) {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
    }

    return 0;
}
