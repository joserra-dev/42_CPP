#!/bin/bash

# Compilar el proyecto
make re > /dev/null

echo "===== TEST ScalarConverter ====="

# Lista de inputs a probar
tests=(
    "a"
    "z"
    "0"
    "42"
    "127"
    "128"
    "-1"
    "2147483647"     # INT_MAX
    "-2147483648"    # INT_MIN
    "42.5"
    "42.5f"
    "nan"
    "nanf"
    "+inf"
    "-inf"
    "+inff"
    "-inff"
)

# Ejecutar todos los tests
for t in "${tests[@]}"; do
    echo
    echo ">>> ./convert \"$t\""
    ./convert "$t"
done
