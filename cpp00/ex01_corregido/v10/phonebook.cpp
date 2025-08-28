#include "phonebook.hpp"
#include "phonebook_utils.hpp"
#include <iomanip>

PhoneBook::PhoneBook() : nb_Contact(0) {}

int PhoneBook::addContact() {
    if (nb_Contact == 8) {
        std::cout << "Memory full: adding new contact will erase the last one.\n";
        std::cout << "Are you sure? (y/n) ➔ ";
        std::string input;
        bool retried = false;

        while (true) {
            if (!std::getline(std::cin, input)) return 0;
            if (input == "y") {
                nb_Contact--;
                break;
            } else if (input == "n") {
                std::cout << "Aborted.\n";
                return 0;
            } else {
                if (retried) clear_previous_lines(2);
                std::cout << "❌ Wrong input\nRETRY           ➔ ";
                retried = true;
            }
        }
    }

    set_homepage();
    std::cout << "\n------ NEW CONTACT ------\n\n";

    std::string input;

    input = enter_info("FIRST NAME");
    if (input.empty()) return -1;
    user[nb_Contact].setFname(input);

    input = enter_info("LAST NAME");
    if (input.empty()) return -1;
    user[nb_Contact].setLname(input);

    input = enter_info("NICKNAME");
    if (input.empty()) return -1;
    user[nb_Contact].setNname(input);

    input = enter_valid_phone();
    if (input.empty()) return -1;
    user[nb_Contact].setnumber(input);

    input = enter_info("DARKEST SECRET");
    if (input.empty()) return -1;
    user[nb_Contact].setsecrets(input);

    user[nb_Contact].setid(nb_Contact);
    nb_Contact++;

    std::cout << "\n✅ CONTACT ADDED\n\n";
    return 1;
}

int PhoneBook::searchContact() {
    if (nb_Contact == 0) {
        std::cout << "Error: No contacts in memory.\n";
        return -1;
    }

    set_homepage();
    std::cout << "\n ___________________________________________\n";
    std::cout << "|                                           |\n";
    std::cout << "|  Index   |First Name| Last Name| Nickname |\n";
    std::cout << "|                                           |\n";

    for (int i = 0; i < nb_Contact; ++i) {
        std::cout << "|";
        std::cout << std::setw(10) << user[i].get_id() + 1 << "|";
        print_Contact(user[i].get_fname()); std::cout << "|";
        print_Contact(user[i].get_lname()); std::cout << "|";
        print_Contact(user[i].get_nname()); std::cout << "|\n";
    }

    std::cout << "|___________________________________________|\n";
    std::cout << "\nQuick search (type index): ";
    std::string input;
    if (!std::getline(std::cin, input)) return 0;

    int idx = ft_stoi(input);
    while (!is_number(input) || idx < 1 || idx > nb_Contact) {
        std::cout << (!is_number(input) ? "\nError: Not a number\n" : "\nError: Index out of range\n");
        std::cout << "Quick search (type index): ";
        if (!std::getline(std::cin, input)) return 0;
        idx = ft_stoi(input);
    }

    set_homepage();
    showContact(idx - 1);
    return 0;
}

int PhoneBook::showContact(int index) {
    std::cout << "\nContact " << index + 1 << ":\n\n";
    std::cout << "FIRST_NAME     = " << user[index].get_fname() << "\n";
    std::cout << "LAST_NAME      = " << user[index].get_lname() << "\n";
    std::cout << "NICKNAME       = " << user[index].get_nname() << "\n";
    std::cout << "NUMBER         = " << user[index].get_pnumber() << "\n";
    std::cout << "DARKEST_SECRET = " << user[index].get_secrets() << "\n\n";
    return 0;
}
