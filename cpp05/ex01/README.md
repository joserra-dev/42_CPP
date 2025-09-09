
---

# 📂 ex01/README.md

```markdown
# C++ Module 05 - ex01

## 📌 Subject

**Exercise 01: Form up, maggots!**

- **Turn-in directory:** `ex01/`
- **Files to turn in:**  
  `Makefile`, `main.cpp`,  
  `Bureaucrat.{hpp,cpp}`,  
  `Form.{hpp,cpp}`
- **Forbidden functions:** None  

### Requirements
- Extend the system by creating a class `Form`:
  - Attributes:
    - `const std::string name`
    - `bool isSigned`
    - `const int signGrade`
    - `const int execGrade`
- A form must be signed by a bureaucrat:
  - `beSigned(Bureaucrat const&)`
- Exceptions for grades out of range:
  - `GradeTooHighException`
  - `GradeTooLowException`
- A `Bureaucrat` can try to sign a form:
  - `signForm(Form&)`

---

## ✅ Solution

### Class Structure
- **`Bureaucrat`**
  - Adds method `signForm(Form&)`

- **`Form`**
  - Attributes: `name`, `isSigned`, `signGrade`, `execGrade`
  - Methods:
    - `beSigned(Bureaucrat const&)`
    - Getters
  - Exceptions:
    - `GradeTooHighException`
    - `GradeTooLowException`

### File Compilation
```bash
make
./bureaucrat


### Main.cpp ejemplo

int main() {
    Bureaucrat boss("Alice", 1);
    Bureaucrat intern("Charlie", 150);

    Form contract("Work Contract", 50, 30);

    intern.signForm(contract);  // should fail
    boss.signForm(contract);    // should succeed

    std::cout << contract << std::endl;
}

### Expected output


Charlie couldn’t sign Work Contract because grade too low
Alice signed Work Contract
Form "Work Contract", signed: true, sign grade: 50, exec grade: 30


###✔️ Checklist

 Form class implemented

 Interaction between Bureaucrat and Form

 Exceptions working

 Overloaded operator<<

 Tests in main.cpp