#include "Client.h"
#include <iostream>

// Konstruktory
Client::Client(const std::string& fName, const std::string& lName,
               const std::string& email, const std::string& phone)
        : Person(fName, lName), email(email), phone(phone) {}

// Gettery
std::string Client::getEmail() const {
    return email;
}

std::string Client::getPhone() const {
    return phone;
}

// Settery
void Client::setEmail(const std::string& newEmail) {
    email = newEmail;
}

void Client::setPhone(const std::string& newPhone) {
    phone = newPhone;
}

void Client::displayClientInfo() const {
    std::cout << "Client: " << getFirstName() << " " << getLastName()
              << ", Email: " << email
              << ", Phone: " << phone << std::endl;
}
