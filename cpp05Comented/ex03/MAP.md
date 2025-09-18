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