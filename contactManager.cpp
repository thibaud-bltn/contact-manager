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

    int choice {-1};
    int currentContact {-1};

    while (choice != 5) {

        std::cout << std::endl;
        std::cout << "=========================================" << std::endl;
        std::cout << "             Edit a contact              " << std::endl;
        std::cout << "=========================================" << std::endl;

        if (contacts.empty()) {
            std::cout << std::endl << "No contacts in phonebook." << std::endl;
            return;
        }

        if (currentContact == -1) {
            while (currentContact < 0 or (currentContact > contacts.size() - 1)) {
                std::cout << "Choose a contact (#ID) : ";
                std::cin >> currentContact;
                std::cout << std::endl;
                --currentContact;
            }
        }

        std::cout << "1. First name" << std::endl
                  << "2. Last name" << std::endl
                  << "3. Phone number" << std::endl
                  << "4. Email" << std::endl
                  << "5. Save contact" << std::endl;

        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Current first name : " << contacts[currentContact].firstName << std::endl;
                std::cout << "New first name: ";
                std::cin >> contacts[currentContact].firstName;
                break;

            case 2:
                std::cout << "Current last name : " << contacts[currentContact].lastName << std::endl;
                std::cout << "New last name: ";
                std::cin >> contacts[currentContact].lastName;
                break;

            case 3:
                std::cout << "Current phone number : " << contacts[currentContact].phoneNumber << std::endl;
                do {
                    std::cout << std::endl << "New phone number: ";
                    std::cin >> contacts[currentContact].phoneNumber;

                    if (!isValidNumber(contacts[currentContact].phoneNumber)) {
                        std::cout << std::endl << "Please enter valid number.";
                    }
                } while (!isValidNumber(contacts[currentContact].phoneNumber));
                break;

            case 4:
                std::cout << "Current email : " << contacts[currentContact].email << std::endl;
                do {
                    std::cout << std::endl << "New email: ";
                    std::cin >> contacts[currentContact].email;

                    if (!isValidEmail(contacts[currentContact].email)) {
                        std::cout << std::endl << "Please enter valid email.";
                    }
                } while (!isValidEmail(contacts[currentContact].email));
                break;

            default:
                break;
        }
    }

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

    for (const Contact& contact : contacts) {
        std::string fullName = contact.firstName + " " + contact.lastName;
        std::cout << std::left << std::setw(4)  << ++id
                  << std::setw(20) << fullName
                  << std::setw(15) << contact.phoneNumber
                  << std::setw(30) << contact.email << std::endl;
    }
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