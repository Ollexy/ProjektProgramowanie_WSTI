//
// Created by rolek on 30.10.2023.
//

#ifndef PROJEKTPROGRAMOWANIE_WSTI_CLIENT_H
#define PROJEKTPROGRAMOWANIE_WSTI_CLIENT_H

#include "Person.h"
#include <string>

class Client : public Person {
private:
    std::string email;
    std::string phone;

public:
    // Konstruktory
    Client(const std::string& fName, const std::string& lName,
           const std::string& email, const std::string& phone);

    // Gettery
    std::string getEmail() const;
    std::string getPhone() const;

    // Settery
    void setEmail(const std::string& newEmail);
    void setPhone(const std::string& newPhone);

    void displayClientInfo() const;
};

#endif


