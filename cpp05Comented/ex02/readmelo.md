🗺️ Mapa Global CPP05/ex02
📌 Clases principales
Bureaucrat

Atributos

const std::string name; → inmutable.

int grade; → 1 (máximo) a 150 (mínimo).

Métodos clave

getName() const → devuelve nombre.

getGrade() const → devuelve rango.

incrementGrade() → sube (disminuye numéricamente).

decrementGrade() → baja (aumenta numéricamente).

signForm(AForm& f) → intenta firmar un formulario.

executeForm(AForm const& f) → intenta ejecutar un formulario.

Excepciones

GradeTooHighException

GradeTooLowException

AForm (abstracta)

Atributos

const std::string name;

bool isSigned;

const int signGrade;

const int execGrade;

std::string target;

Métodos

beSigned(Bureaucrat const& b) → firma si el burócrata tiene rango suficiente.

execute(Bureaucrat const& b) const = 0; (puro, implementado en derivados).

Excepciones

GradeTooHighException

GradeTooLowException

FormNotSignedException

ShrubberyCreationForm : AForm

Objetivo: crear un archivo <target>_shrubbery con un ASCII tree 🌲.

execute(Bureaucrat const& b) const → valida permisos y escribe el arbolito.

RobotomyRequestForm : AForm

Objetivo: simula una robotomización del target.

execute(Bureaucrat const& b) const → 50% éxito, 50% fracaso (con srand/rand).

PresidentialPardonForm : AForm

Objetivo: imprimir que el target fue perdonado por Zaphod Beeblebrox 👑.

execute(Bureaucrat const& b) const → valida permisos y muestra el mensaje.

📌 Relación entre clases

Bureaucrat puede firmar (signForm) y ejecutar (executeForm) formularios.

AForm es la clase base abstracta de la que heredan los 3 formularios concretos.

Cada form implementa su propia execute().

📌 Excepciones clave

Bureaucrat:

GradeTooHighException si se pasa de rango.

GradeTooLowException si el rango no alcanza.

AForm:

GradeTooHighException / GradeTooLowException.

FormNotSignedException al ejecutar un form no firmado.

📌 Makefile

Compila: main.cpp, Bureaucrat.cpp, AForm.cpp, y los 3 formularios.

Targets: all, clean, fclean, re.

📌 Main de pruebas

Crea 3 burócratas: uno top (1), uno medio (50) y uno bajo (150).

Prueba cada formulario con casos de éxito y fallo.

Muestra mensajes claros de firma/ejecución o errores por excepciones.