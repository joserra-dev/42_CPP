#include "functions.hpp"

int main() {
    srand(time(NULL));

    for (int i = 0; i < 5; i++) {
        std::cout << "=== Test " << i + 1 << " ===" << std::endl;
        Base* obj = generate();

        identify(obj);
        identify(*obj);

        delete obj;
        std::cout << std::endl;
    }

    return 0;
}
