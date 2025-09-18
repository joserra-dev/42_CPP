#include "ScalarConverter.hpp"

// Constructores privados
ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    (void)other;
    return *this;
}
ScalarConverter::~ScalarConverter() {}

// ------------------ Helpers de impresión ------------------

void ScalarConverter::printChar(double value) {
    std::cout << "char: ";
    if (std::isnan(value) || value < 0 || value > 127) {
        std::cout << "impossible" << std::endl;
    } else if (!std::isprint(static_cast<int>(value))) {
        std::cout << "Non displayable" << std::endl;
    } else {
        std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
    }
}

void ScalarConverter::printInt(double value) {
    std::cout << "int: ";
    if (std::isnan(value) || value < INT_MIN || value > INT_MAX) {
        std::cout << "impossible" << std::endl;
    } else {
        std::cout << static_cast<int>(value) << std::endl;
    }
}

void ScalarConverter::printFloat(double value) {
    std::cout << "float: ";
    if (std::isnan(value))
        std::cout << "nanf" << std::endl;
    else if (std::isinf(value))
        std::cout << (value < 0 ? "-inff" : "+inff") << std::endl;
    else {
        std::cout << std::fixed << std::setprecision(1)
                  << static_cast<float>(value) << "f" << std::endl;
    }
}

void ScalarConverter::printDouble(double value) {
    std::cout << "double: ";
    if (std::isnan(value))
        std::cout << "nan" << std::endl;
    else if (std::isinf(value))
        std::cout << (value < 0 ? "-inf" : "+inf") << std::endl;
    else {
        std::cout << std::fixed << std::setprecision(1)
                  << value << std::endl;
    }
}

// ------------------ Convert ------------------

void ScalarConverter::convert(const std::string& literal) {
    // Casos especiales primero
    if (literal == "nan" || literal == "nanf") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
        return;
    }
    if (literal == "+inf" || literal == "+inff") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
        return;
    }
    if (literal == "-inf" || literal == "-inff") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
        return;
    }

    double value = 0.0;

    // Char suelto
    if (literal.length() == 1 && !std::isdigit(literal[0])) {
        value = static_cast<double>(literal[0]);
    }
    // Float (termina en f y contiene '.')
    else if (literal[literal.size() - 1] == 'f' && literal.find('.') != std::string::npos) {
        value = static_cast<double>(std::atof(literal.c_str()));
    }
    // Double (contiene '.' pero no termina en 'f')
    else if (literal.find('.') != std::string::npos) {
        value = static_cast<double>(std::atof(literal.c_str()));
    }
    // Int
    else {
        value = static_cast<double>(std::atoi(literal.c_str()));
    }

    // Imprimir todas las conversiones
    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}
