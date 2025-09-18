#include "functions.hpp"
#include <typeinfo>

Base* generate(void) {
    int r = rand() % 3;
    switch (r) {
        case 0: std::cout << "Generated A" << std::endl; return new A();
        case 1: std::cout << "Generated B" << std::endl; return new B();
        default: std::cout << "Generated C" << std::endl; return new C();
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "Pointer to A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Pointer to B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Pointer to C" << std::endl;
    else
        std::cout << "Pointer unknown" << std::endl;
}

void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "Reference to A" << std::endl;
        return;
    } catch (std::bad_cast&) {}

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "Reference to B" << std::endl;
        return;
    } catch (std::bad_cast&) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "Reference to C" << std::endl;
        return;
    } catch (std::bad_cast&) {}

    std::cout << "Reference unknown" << std::endl;
}
