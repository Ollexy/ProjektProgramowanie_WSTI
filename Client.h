//
// Created by rolek on 30.10.2023.
//

#ifndef PROJEKTPROGRAMOWANIE_WSTI_CLIENT_H
#define PROJEKTPROGRAMOWANIE_WSTI_CLIENT_H

#include <iostream>
#include "Person.h"

class Client : public Person {
private:
    int id;
    std::string email;

public:
    Client(std::string fName, std::string lName, int xAge, int xId, std::string xEmail);

    void displayInfo() const override;
};


#endif //PROJEKTPROGRAMOWANIE_WSTI_CLIENT_H
