<<<<<<< HEAD
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
=======
🗺️ Mapa inicial – CPP05 / ex03 (Intern)
📌 Subject

Directorio: ex03/

Archivos:

Makefile, main.cpp

Bureaucrat.{hpp,cpp}

AForm.{hpp,cpp}

ShrubberyCreationForm.{hpp,cpp}

RobotomyRequestForm.{hpp,cpp}

PresidentialPardonForm.{hpp,cpp}

Intern.{hpp,cpp}

Funciones prohibidas: Ninguna

Requisitos

Crear una clase Intern que puede generar formularios sin conocer de antemano su tipo.

Método principal:

AForm* makeForm(std::string const& formName, std::string const& target);


Devuelve un puntero al nuevo formulario (ShrubberyCreationForm, RobotomyRequestForm, o PresidentialPardonForm).

Si formName no coincide con ninguno, lanza un mensaje o excepción.

✅ Clases y relaciones

Intern

Métodos:

makeForm(std::string const& name, std::string const& target)

Usa una tabla de correspondencias:

{"shrubbery creation", &Intern::createShrubbery}
{"robotomy request", &Intern::createRobotomy}
{"presidential pardon", &Intern::createPardon}


Cada createX es una función privada que devuelve un AForm*.

Bureaucrat

Igual que en ex02.

Puede firmar y ejecutar los formularios creados por Intern.

AForm

Igual que en ex02 (abstracta).

Formularios concretos

ShrubberyCreationForm, RobotomyRequestForm, PresidentialPardonForm

Heredan de AForm y se construyen con un target.

🏗️ Flujo esperado

El main crea un Intern.

Se le pide que genere distintos formularios:

Intern someRandomIntern;
AForm* form;
form = someRandomIntern.makeForm("robotomy request", "Bender");


El formulario se devuelve dinámicamente (new), luego se firma y ejecuta con un Bureaucrat.

Si se pide un formulario inexistente:

form = someRandomIntern.makeForm("invalid form", "Target");


→ Debe mostrar un mensaje de error.

📂 Estructura de archivos
ex03/
│── Makefile
│── main.cpp
│── Bureaucrat.cpp / Bureaucrat.hpp
│── AForm.cpp / AForm.hpp
│── ShrubberyCreationForm.cpp / ShrubberyCreationForm.hpp
│── RobotomyRequestForm.cpp / RobotomyRequestForm.hpp
│── PresidentialPardonForm.cpp / PresidentialPardonForm.hpp
│── Intern.cpp / Intern.hpp

✔️ Checklist

 Clase Intern creada.

 Método makeForm devuelve el formulario correcto.

 Manejo de formulario inexistente.

 Pruebas en main.cpp mostrando creación + firma + ejecución.

 Makefile compila todo.
>>>>>>> 38abecfe4b986073e9f84a38c7763281d5d04e4e
