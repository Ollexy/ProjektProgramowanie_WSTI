//
// Created by rolek on 30.10.2023.
//

#include "Client.h"

Client::Client(std::string firstName, std::string lastName, int age, int id, std::string email)
    :Person(firstName, lastName, age), id(id), email(email){}

void Client::displayInfo() const {
    std::cout << "Client: " << firstName << " " << lastName << std:: endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "ID: " << id << std::endl;
    std::cout << "E-mail: " << email << std::endl << std::endl << std::endl;
}
