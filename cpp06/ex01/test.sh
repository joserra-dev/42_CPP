#!/bin/bash

# Compilar el proyecto
make re > /dev/null

echo "===== TEST Serializer ====="

# Ejecutamos el binario varias veces para ver que serialize/deserialize funcionan
for i in {1..5}; do
    echo
    echo ">>> Test $i"
    ./serialization
done
echo
echo "===== VALGRIND CHECK ====="
valgrind --leak-check=full --show-leak-kinds=all ./serialization