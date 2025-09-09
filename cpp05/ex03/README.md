📌 CPP05 – ex03: Intern
📝 Descripción

En este ejercicio añadimos la clase Intern, cuya función es fabricar formularios bajo demanda.
El Intern recibe el nombre del formulario a crear en forma de cadena (std::string) y devuelve un puntero al objeto recién creado (AForm*).

El objetivo es aplicar el patrón Factory Method en C++.

📂 Clases principales

Bureaucrat

Clase que representa un burócrata con un nombre y un grade (1 = más alto, 150 = más bajo).

Puede firmar y ejecutar formularios.

AForm

Clase abstracta que representa un formulario genérico.

Define la interfaz común de todos los formularios concretos.

Contiene:

Nombre

Estado de firmado (bool)

Grado requerido para firmar

Grado requerido para ejecutar

Formularios concretos

ShrubberyCreationForm

RobotomyRequestForm

PresidentialPardonForm

Intern

Clase capaz de crear formularios automáticamente.

Método principal:

AForm* makeForm(const std::string& formName, const std::string& target);


Según el formName devuelve:

"shrubbery creation" → ShrubberyCreationForm

"robotomy request" → RobotomyRequestForm

"presidential pardon" → PresidentialPardonForm

Si no reconoce el formulario, devuelve NULL (o lanza excepción, según implementación).

📂 Ejemplo de uso (main.cpp)
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <iostream>

int main() {
    Intern intern;
    Bureaucrat boss("Boss", 1);

    std::cout << "\n=== Intern crea formularios ===\n";
    AForm* shrub = intern.makeForm("shrubbery creation", "home");
    AForm* robo  = intern.makeForm("robotomy request", "Bender");
    AForm* pardon = intern.makeForm("presidential pardon", "Morty");
    AForm* unknown = intern.makeForm("coffee form", "office"); // inválido

    std::cout << "\n=== Bureaucrat interactúa con los formularios ===\n";
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

    if (!unknown) {
        std::cout << "Intern no pudo crear ese formulario.\n";
    }

    return 0;
}

⚙️ Compilación

Con el Makefile incluido:

make


Ejecutar:

./bureaucrat

✅ Ejemplo de salida esperada
=== Intern crea formularios ===
Intern crea ShrubberyCreationForm
Intern crea RobotomyRequestForm
Intern crea PresidentialPardonForm
Intern no pudo crear formulario: coffee form

=== Bureaucrat interactúa con los formularios ===
Boss signed ShrubberyCreationForm
Boss executed ShrubberyCreationForm
Boss signed RobotomyRequestForm
Bzzzz... drilling noises... Bender ha sido robotomizado con éxito.
Boss executed RobotomyRequestForm
Boss signed PresidentialPardonForm
Morty ha sido perdonado por el presidente Zaphod Beeblebrox.
Boss executed PresidentialPardonForm
Intern no pudo crear ese formulario.
