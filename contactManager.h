#ifndef CONTACTMANAGER_CONTACTMANAGER_H
#define CONTACTMANAGER_CONTACTMANAGER_H

#include <string>

struct Contact {
    std::string firstName;
    std::string lastName;
    int phoneNumber;
    std::string email;
};

#endif