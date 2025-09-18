#include "Serializer.hpp"

int main() {
    Data d;
    d.name = "Canalla";
    d.value = 42;

    std::cout << "Original struct: " << d.name << " = " << d.value << std::endl;

    uintptr_t raw = Serializer::serialize(&d);
    std::cout << "Serialized value (uintptr_t): " << raw << std::endl;

    Data* ptr = Serializer::deserialize(raw);
    std::cout << "Deserialized struct: " << ptr->name << " = " << ptr->value << std::endl;

    return 0;
}
