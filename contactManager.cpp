#include "contactManager.h"

bool isValidNumber(const std::string& phoneNumber) {
    for (char c : phoneNumber) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return phoneNumber.size() == 10;
}

bool isValidEmail(const std::string& email) {
    size_t atPos = email.find('@');
    size_t dotPos = email.find('.', atPos);

    return (atPos != std::string::npos)
           and (dotPos != std::string::npos)
           and (atPos > 0)
           and (dotPos > atPos + 1)
           and (dotPos < email.size() - 1);
}

void addContact(std::vector<Contact>& contacts) {
    Contact contact {"", "", "", ""};

    std::cout << std::endl;
    std::cout << "=========================================" << std::endl;
    std::cout << "              Add a contact              " << std::endl;
    std::cout << "=========================================" << std::endl;

    std::cout << "First name: ";
    std::cin >> contact.firstName;

    std::cout << std::endl << "Last name: ";
    std::cin >> contact.lastName;

    do {
        std::cout << std::endl << "Phone number: ";
        std::cin >> contact.phoneNumber;

        if (!isValidNumber(contact.phoneNumber)) {
            std::cout << std::endl << "Please enter valid number.";
        }
    } while (!isValidNumber(contact.phoneNumber));

    do {
        std::cout << std::endl << "Email: ";
        std::cin >> contact.email;

        if (!isValidEmail(contact.email)) {
            std::cout << std::endl << "Please enter valid email.";
        }
    } while (!isValidEmail(contact.email));

    contacts.push_back(contact);

    std::cout << std::endl << "Contact successfully created (#" << contacts.size() << ")" << std::endl;
    std::cout << "-----------------------------------------" << std::endl << std::endl;
}

void printBanner() {
    std::cout << "   ______            __             __     __  ___                                 " << std::endl
              << "  / ____/___  ____  / /_____ ______/ /_   /  |/  /___ _____  ____ _____ ____  _____" << std::endl
              << " / /   / __ \\/ __ \\/ __/ __ `/ ___/ __/  / /|_/ / __ `/ __ \\/ __ `/ __ `/ _ \\/ ___/" << std::endl
              << "/ /___/ /_/ / / / / /_/ /_/ / /__/ /_   / /  / / /_/ / / / / /_/ / /_/ /  __/ /" << std::endl
              << "\\____/\\____/_/ /_/\\__/\\__,_/\\___/\\__/  /_/  /_/\\__,_/_/ /_/\\__,_/\\__, /\\___/_/" << std::endl
              << "                                                                /____/             " << std::endl
              << std::endl;
}

void printMenu() {
    std::cout << std::endl;
    std::cout << "=========================================" << std::endl;
    std::cout << "             Contact Manager             " << std::endl;
    std::cout << "=========================================" << std::endl;
    std::cout << "1. Add a contact" << std::endl
              << "2. Edit a contact" << std::endl
              << "3. Delete a contact" << std::endl
              << "4. Show contacts" << std::endl
              << "5. Leave" << std::endl;
    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "Select an option: ";
}