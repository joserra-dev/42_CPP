#include "phonebook.hpp"
#include <iostream>

int main() {
    PhoneBook phonebook;
    std::string command;

    while (true) {
        std::cout << "📒 PHONEBOOK\nAvailable commands: ADD | SEARCH | EXIT\n➔ ";
        if (!std::getline(std::cin, command)) {
            std::cout << "\nEOF detected. Exiting.\n";
            break;
        }

        if (command == "ADD") {
            phonebook.addContact();
        } else if (command == "SEARCH") {
            phonebook.searchContact();
        } else if (command == "EXIT") {
            std::cout << "Bye!\n";
            break;
        } else if (!command.empty()) {
            std::cout << "❌ Unknown command. Try ADD, SEARCH, or EXIT.\n";
        }
    }

    return 0;
}
