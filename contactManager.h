#ifndef CONTACTMANAGER_CONTACTMANAGER_H
#define CONTACTMANAGER_CONTACTMANAGER_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

struct Contact {
    std::string firstName;
    std::string lastName;
    std::string phoneNumber;
    std::string email;
};

bool isValidNumber(const std::string& phoneNumber);

bool isValidEmail(const std::string& email);

void addContact(std::vector<Contact>& contacts);

void editContact(std::vector<Contact>& contacts);

void showContact(const std::vector<Contact>& contacts);

void printBanner();

void printMenu();

#endif