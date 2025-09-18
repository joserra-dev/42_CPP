# C++ Module 05 - ex02

## 📌 Descripción

Este ejercicio extiende el proyecto de los **burócratas y formularios**, añadiendo la posibilidad de crear diferentes tipos de formularios especializados:

* **ShrubberyCreationForm** 🌳 → Crea un archivo con un arbolito ASCII.
* **RobotomyRequestForm** 🤖 → Intenta robotizar a alguien (50% de éxito).
* **PresidentialPardonForm** 🎩 → Otorga un perdón presidencial.

Cada formulario hereda de una clase abstracta `AForm`, y los **burócratas** (`Bureaucrat`) pueden **firmar** y **ejecutar** estos formularios según su grado.

---

## 📂 Estructura del proyecto

```
ex02/
├── Makefile
├── main.cpp
├── Bureaucrat.cpp
├── Bureaucrat.hpp
├── AForm.cpp
├── AForm.hpp
├── ShrubberyCreationForm.cpp
├── ShrubberyCreationForm.hpp
├── RobotomyRequestForm.cpp
├── RobotomyRequestForm.hpp
├── PresidentialPardonForm.cpp
└── PresidentialPardonForm.hpp
```

---

## 🏛️ Clases principales

### Bureaucrat

* **Atributos:**

  * `const std::string name;`
  * `int grade;` (1 = mejor, 150 = peor)
* **Métodos:**

  * `signForm(AForm&)` → Intenta firmar un formulario.
  * `executeForm(AForm const&)` → Intenta ejecutar un formulario.
  * `incrementGrade()` / `decrementGrade()` → Ajusta el rango.
* **Excepciones:**

  * `GradeTooHighException`
  * `GradeTooLowException`

### AForm (abstracta)

* **Atributos:**

  * `const std::string name;`
  * `bool isSigned;`
  * `const int gradeToSign;`
  * `const int gradeToExecute;`
* **Métodos:**

  * `beSigned(Bureaucrat const&)`
  * `execute(Bureaucrat const&) const = 0;` (método puro virtual)
* **Excepciones:**

  * `GradeTooHighException`
  * `GradeTooLowException`
  * `FormNotSignedException`

### ShrubberyCreationForm

* **Objetivo:** Crear un archivo `<target>_shrubbery` con arte ASCII de un árbol.
* **Requiere:** sign grade 145, exec grade 137.

### RobotomyRequestForm

* **Objetivo:** Simula una robotización con 50% de éxito.
* **Requiere:** sign grade 72, exec grade 45.

### PresidentialPardonForm

* **Objetivo:** Imprime un perdón presidencial.
* **Requiere:** sign grade 25, exec grade 5.

---

## ⚙️ Compilación

```bash
make
```

Esto genera el ejecutable **`bureaucrat`**.

Para limpiar:

```bash
make clean
make fclean
```

---

## ▶️ Ejemplo de uso (main.cpp)

```cpp
int main() {
    try {
        Bureaucrat high("Alice", 1);
        Bureaucrat mid("Bob", 50);
        Bureaucrat low("Charlie", 150);

        ShrubberyCreationForm shrub("home");
        RobotomyRequestForm robo("Bender");
        PresidentialPardonForm pardon("Morty");

        // Intentos de firma y ejecución
        low.signForm(shrub);
        high.signForm(shrub);
        high.executeForm(shrub);

        mid.signForm(robo);
        high.executeForm(robo);

        high.signForm(pardon);
        mid.executeForm(pardon);
        high.executeForm(pardon);
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}
```

---

## 📖 Notas importantes

* Un **burócrata** solo puede:

  * **Firmar** si su `grade` ≤ `gradeToSign` del formulario.
  * **Ejecutar** si el formulario ya está firmado y su `grade` ≤ `gradeToExecute`.
* La sobrecarga de `<<` en `Bureaucrat` y `AForm` permite imprimirlos en consola.
* Se utilizan **excepciones personalizadas** para un manejo claro de errores.

---

## ✅ Checklist ex02

* [x] `AForm` como clase abstracta.
* [x] Formularios derivados (`ShrubberyCreationForm`, `RobotomyRequestForm`, `PresidentialPardonForm`).
* [x] Métodos `signForm` y `executeForm` en `Bureaucrat`.
* [x] Excepciones manejadas con `try/catch`.
* [x] Makefile funcional.
* [x] `main.cpp` de prueba.

---

👨‍💻 Proyecto completado siguiendo las reglas de **C++98** y la **Forma Ortodoxa Canónica** para las clases requeridas.
