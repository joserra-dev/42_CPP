#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main() {
    Intern someRandomIntern;
    Bureaucrat boss("Boss", 1);

    std::cout << "\n--- Creación de formularios por el Intern ---" << std::endl;

    AForm* shrub = someRandomIntern.makeForm("shrubbery creation", "Home");
    AForm* robo = someRandomIntern.makeForm("robotomy request", "Bender");
    AForm* pardon = someRandomIntern.makeForm("presidential pardon", "Alice");

    AForm* unknown = someRandomIntern.makeForm("coffee request", "Office");

    std::cout << "\n--- Probando interacción con Bureaucrat ---" << std::endl;

    if (shrub) {
        boss.signForm(*shrub);
        boss.executeForm(*shrub);
        delete shrub;
    }

    if (robo) {
        boss.signForm(*robo);
        boss.executeForm(*robo);
        delete robo;
    }

    if (pardon) {
        boss.signForm(*pardon);
        boss.executeForm(*pardon);
        delete pardon;
    }

    if (unknown) {
        boss.signForm(*unknown);
        boss.executeForm(*unknown);
        delete unknown;
    }

    return 0;
}
