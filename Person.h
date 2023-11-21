//
// Created by rolek on 30.10.2023.
//

#ifndef PROJEKTPROGRAMOWANIE_WSTI_PERSON_H
#define PROJEKTPROGRAMOWANIE_WSTI_PERSON_H

#include <string>

class Person {
protected:
    std::string firstName;
    std::string lastName;
    int age;

public:
    Person(std::string firstName, std::string lastName, int age);
    virtual ~Person() = default;

    virtual void displayInfo() const = 0;

};


#endif //PROJEKTPROGRAMOWANIE_WSTI_PERSON_H
