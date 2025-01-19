#include "contactManager.h"

int main() {

    int choice {-1};
    std::vector<Contact> contacts;

    printBanner();

    while (choice != 5) {

        printMenu();

        std::cin >> choice;

        switch (choice) {
            case 1:
                addContact(contacts);
                break;

            case 2:
                editContact(contacts);
                break;

            case 3:
                break;

            case 4:
                showContact(contacts);
                break;

            default:
                break;
        }
    }

    return 0;
}