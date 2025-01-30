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
    Person(const std::string& fName, const std::string& lName);
    Person(const std::string &fName, const std::string &lName, int age);
    virtual ~Person() = default;

    // Gettery
    std::string getFirstName() const;
    std::string getLastName() const;
    int getAge() const;

    // Settery
    void setFirstName(const std::string &fName);
    void setLastName(const std::string &lName);
    void setAge(int age);
};


#endif
