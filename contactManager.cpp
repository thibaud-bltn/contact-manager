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

void editContact(std::vector<Contact>& contacts) {

    int currentContact {-1};
    std::string firstName, lastName, phoneNumber, email;

    std::cout << std::endl;
    std::cout << "=========================================" << std::endl;
    std::cout << "             Edit a contact              " << std::endl;
    std::cout << "=========================================" << std::endl;

    if (contacts.empty()) {
        std::cout << std::endl << "No contacts in phonebook." << std::endl;
        return;
    }

    while (currentContact < 0 or (currentContact > contacts.size() - 1)) {
        std::cout << "Choose a contact (#ID) : ";
        std::cin >> currentContact;
        std::cout << std::endl;
        --currentContact;
    }

    std::cout << "-----------------------------------------" << std::endl
              << "Selected contact:" << std::endl
              << "First name: " << contacts[currentContact].firstName << std::endl
              << "Last name: " << contacts[currentContact].lastName << std::endl
              << "Phone number: " << contacts[currentContact].phoneNumber << std::endl
              << "Email: " << contacts[currentContact].email << std::endl
              << "-----------------------------------------" << std::endl;

    std::cin.ignore();

    std::cout << std::endl << "Enter new first name (leave empty to keep : " << contacts[currentContact].firstName << "): ";
    std::getline(std::cin, firstName);
    if (!firstName.empty()) contacts[currentContact].firstName = firstName;

    std::cout << std::endl << "Enter new last name (leave empty to keep : " << contacts[currentContact].lastName << "): ";
    std::getline(std::cin, lastName);
    if (!lastName.empty()) contacts[currentContact].lastName = lastName;

    do {
        std::cout << std::endl << "Enter new phone number (leave empty to keep : " << contacts[currentContact].phoneNumber << "): ";
        std::getline(std::cin, phoneNumber);

        if (phoneNumber.empty()) break;

        if (!isValidNumber(phoneNumber)) {
            std::cout << std::endl << "Please enter valid number.";
        }
    } while (!isValidNumber(phoneNumber));
    if (!phoneNumber.empty()) contacts[currentContact].phoneNumber = phoneNumber;

    do {
        std::cout << std::endl << "Enter new email (leave empty to keep : " << contacts[currentContact].email << "): ";
        std::getline(std::cin, email);

        if (email.empty()) break;

        if (!isValidEmail(email)) {
            std::cout << std::endl << "Please enter valid email.";
        }
    } while (!isValidEmail(email));
    if (!email.empty()) contacts[currentContact].email = email;

    std::cout << std::endl << "Contact successfully edited" << std::endl;
    std::cout << "-----------------------------------------" << std::endl << std::endl;
}

void showContact(const std::vector<Contact>& contacts) {

    std::cout << std::endl;
    std::cout << "=========================================" << std::endl;
    std::cout << "            List of contacts             " << std::endl;
    std::cout << "=========================================" << std::endl;

    if (contacts.empty()) {
        std::cout << std::endl << "No contacts in phonebook." << std::endl;
        return;
    }

    int id {0};

    std::cout << std::left << std::setw(4)  << "ID"
              << std::setw(20) << "Name"
              << std::setw(15) << "Phone number"
              << std::setw(30) << "Email" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;

    for (const Contact& contact : contacts) {
        std::string fullName = contact.firstName + " " + contact.lastName;
        std::cout << std::left << std::setw(4)  << ++id
                  << std::setw(20) << fullName
                  << std::setw(15) << contact.phoneNumber
                  << std::setw(30) << contact.email << std::endl;
    }
    std::cout << "--------------------------------------------------------" << std::endl;
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