#pragma once
#include <iostream>
#include <string>
#include <cctype>
#include <limits>
#include <iomanip>
#include <algorithm>

// Limpia líneas anteriores en consola
inline void clear_previous_lines(int n = 1) {
    for (int i = 0; i < n; ++i)
        std::cout << "\033[1A\033[K";
}

// Verifica si un string contiene solo dígitos
inline bool is_number(const std::string& str) {
    return !str.empty() && std::all_of(str.begin(), str.end(), [](char c) {
        return std::isdigit(static_cast<unsigned char>(c));
    });
}

// Conversión segura de string a int
inline int ft_stoi(const std::string& str) {
    int n = 0;
    for (char c : str)
        n = n * 10 + (c - '0');
    return n;
}

// Entrada de texto genérica no vacía
inline std::string enter_info(const std::string& label) {
    std::string input;
    std::string padding(16 - label.length(), ' ');
    bool retried = false;

    while (true) {
        if (retried)
            clear_previous_lines(2);
        std::cout << label << padding << "➔ ";
        if (!std::getline(std::cin, input))
            return "";
        if (!input.empty()) {
            clear_previous_lines(1);
            std::cout << label << padding << "➔ " << input << " ✅" << std::endl;
            return input;
        }
        std::cout << "❌ Empty input\nRETRY           ➔ ";
        retried = true;
    }
}

// Entrada validada de número de teléfono (10 dígitos)
inline std::string enter_valid_phone() {
    std::string phone;
    bool retried = false;

    while (true) {
        if (retried)
            clear_previous_lines(2);
        std::cout << "NUMBER          ➔ ";
        if (!std::getline(std::cin, phone)) return "";
        if (phone.length() == 10 && is_number(phone)) {
            clear_previous_lines(1);
            std::cout << "NUMBER          ➔ " << phone << " ✅" << std::endl;
            return phone;
        }
        std::cout << "Error: Phone number must be 10 digits long and numeric." << std::endl;
        retried = true;
    }
}

// Truncado/formato para tabla
inline void print_Contact(const std::string& str) {
    if (str.length() > 10)
        std::cout << str.substr(0, 9) << ".";
    else
        std::cout << std::setw(10) << str;
}

// Muestra banner principal
inline void set_homepage() {
    std::cout << "\033c"; // limpia terminal
    std::cout << "========================\n";
    std::cout << "     MY PHONEBOOK       \n";
    std::cout << "========================\n";
}
