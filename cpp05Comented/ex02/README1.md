# C++ Module 05 - ex02

## 📌 Subject

**Exercise 02: Bureaucracy at its finest**

- **Turn-in directory:** `ex02/`
- **Files to turn in:**  
  `Makefile`, `main.cpp`,  
  `Bureaucrat.{hpp,cpp}`,  
  `AForm.{hpp,cpp}`,  
  `ShrubberyCreationForm.{hpp,cpp}`,  
  `RobotomyRequestForm.{hpp,cpp}`,  
  `PresidentialPardonForm.{hpp,cpp}`  
- **Forbidden functions:** None  

### Requirements
- Create an abstract class `AForm`, inherited by three concrete forms:  
  - `ShrubberyCreationForm` → creates a file with ASCII trees 🌳  
  - `RobotomyRequestForm` → attempts a robotomy with 50% chance 🤖  
  - `PresidentialPardonForm` → pardons a target by Zaphod Beeblebrox 👑  
- A form can only be executed if:  
  1. It is signed.  
  2. The bureaucrat executing it has a grade high enough.  
- `Bureaucrat` must be able to:  
  - Sign forms (`signForm`)  
  - Execute forms (`executeForm`)  
- Use exceptions for invalid grades, unsigned forms, and insufficient grade execution.  

---

## ✅ Solution

### Class Structure
- **`Bureaucrat`**
  - Attributes: `const std::string name`, `int grade`
  - Methods: `signForm(Form&)`, `executeForm(Form const&)`, grade increment/decrement
  - Exceptions: `GradeTooHighException`, `GradeTooLowException`

- **`AForm` (abstract)**
  - Attributes: `const std::string name`, `bool isSigned`, `int signGrade`, `int execGrade`
  - Methods: `beSigned(Bureaucrat const&)`, `execute(Bureaucrat const&) = 0`
  - Exceptions: `GradeTooHighException`, `GradeTooLowException`, `FormNotSignedException`

- **Concrete forms**
  - `ShrubberyCreationForm` → creates `<target>_shrubbery` file with ASCII tree
  - `RobotomyRequestForm` → prints success/failure with 50% chance
  - `PresidentialPardonForm` → prints a pardon message

### File Compilation
```bash
make        # compiles into ./bureaucrat
make clean  # removes objects
make fclean # removes objects + binary
make re     # rebuild

### Example main.cpp ###

int main() {
    Bureaucrat high("Alice", 1);
    Bureaucrat mid("Bob", 70);
    Bureaucrat low("Charlie", 150);

    ShrubberyCreationForm shrub("garden");
    RobotomyRequestForm robo("Bender");
    PresidentialPardonForm pardon("Marvin");

    low.signForm(shrub);      // fail (too low)
    high.signForm(shrub);     // success
    high.executeForm(shrub);  // creates file with ASCII tree

    mid.signForm(robo);       // success
    high.executeForm(robo);   // 50% robotomy chance

    high.signForm(pardon);    // success
    high.executeForm(pardon); // pardon message
}

### Expected Output (example)
Charlie couldn’t sign ShrubberyCreationForm because grade too low
Alice signed ShrubberyCreationForm
Alice executed ShrubberyCreationForm
Bob signed RobotomyRequestForm
Alice executed RobotomyRequestForm: drilling noises... success!
Alice signed PresidentialPardonForm
Alice executed PresidentialPardonForm: Marvin has been pardoned by Zaphod Beeblebrox


✔️ Checklist

 Bureaucrat implemented with exceptions

 Abstract AForm class

 Three concrete forms (Shrubbery, Robotomy, PresidentialPardon)

 Exceptions for invalid grades and unsigned forms

 Overloaded operator<< for pretty printing

 Tests in main.cpp