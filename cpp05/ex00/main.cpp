#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat b1("Alice", 2);
        Bureaucrat b2("Bob", 149);

        std::cout << b1 << std::endl;
        std::cout << b2 << std::endl;

        b1.incrementGrade(); // debería funcionar (2 -> 1)
        std::cout << b1 << std::endl;

        // Esto debería lanzar excepción
        b1.incrementGrade();
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b3("Charlie", 200); // excepción al construir
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
