#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include <cstdlib>
#include <cerrno>
#include <cmath>
#include <climits>
#include <cfloat>

class ScalarConverter {
private:
    // Constructor privado para impedir instanciación
    ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& other);
    ~ScalarConverter();

    // Helpers de impresión
    static void printChar(double value);
    static void printInt(double value);
    static void printFloat(double value);
    static void printDouble(double value);

public:
    // Método estático principal
    static void convert(const std::string& literal);
};

#endif
