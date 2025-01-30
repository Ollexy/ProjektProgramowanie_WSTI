//
// Created by rolek on 30.10.2023.
//

#include "Person.h"

Person::Person(const std::string& fName, const std::string& lName)
        : firstName(fName), lastName(lName) {}

Person::Person(const std::string &fName, const std::string &lName, int age)
        : firstName(fName), lastName(lName), age(age) {}

std::string Person::getFirstName() const {
    return firstName;
}

std::string Person::getLastName() const {
    return lastName;
}

int Person::getAge() const {
    return age;
}

void Person::setFirstName(const std::string &fName) {
    firstName = fName;
}

void Person::setLastName(const std::string &lName) {
    lastName = lName;
}

void Person::setAge(int age) {
    this->age = age;
}

