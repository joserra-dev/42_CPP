# C++ Module 05 - ex00

## 📌 Subject

**Exercise 00: Mommy, when I grow up, I want to be a bureaucrat!**

- **Turn-in directory:** `ex00/`
- **Files to turn in:**  
  `Makefile`, `main.cpp`, `Bureaucrat.{hpp,cpp}`
- **Forbidden functions:** None  

### Requirements
- Create a class `Bureaucrat` with:
  - A constant `name`
  - An integer `grade` (1 = highest, 150 = lowest)
- Any invalid grade must throw:
  - `GradeTooHighException`
  - `GradeTooLowException`
- Methods:
  - `getName()`, `getGrade()`
  - `incrementGrade()`, `decrementGrade()`
- Overload `operator<<` to print:



---

## ✅ Solution

### Class Structure
- **`Bureaucrat`**
- Attributes: `const std::string name`, `int grade`
- Methods:  
  - `getName()`, `getGrade()`  
  - `incrementGrade()`, `decrementGrade()` (throws if out of range)
- Exceptions: `GradeTooHighException`, `GradeTooLowException`

### File Compilation
```bash
make
./bureaucrat

###  main.cpp ejemplo
int main() {
    try {
        Bureaucrat b1("Alice", 2);
        std::cout << b1 << std::endl;

        b1.incrementGrade();
        std::cout << b1 << std::endl;

        b1.incrementGrade(); // should throw
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

### expected output
Alice, bureaucrat grade 2.
Alice, bureaucrat grade 1.
Exception: grade too high!


✔️ Checklist

 Bureaucrat with name and grade

 Exceptions working

 Increment/decrement logic

 Overloaded operator<<

 Tests in main.cpp