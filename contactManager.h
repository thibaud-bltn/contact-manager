#ifndef CONTACTMANAGER_CONTACTMANAGER_H
#define CONTACTMANAGER_CONTACTMANAGER_H

#include <iostream>
#include <string>
#include <vector>

struct Contact {
    std::string firstName;
    std::string lastName;
    int phoneNumber;
    std::string email;
};

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

#endif