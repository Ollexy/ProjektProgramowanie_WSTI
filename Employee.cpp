#include "Employee.h"

Employee::Employee(const std::string &fName, const std::string &lName, int age, const std::string &position, double salary)
        : firstName(fName), lastName(lName), age(age), position(position), salary(salary) {}

const std::string& Employee::getFirstName() const {
    return firstName;
}

const std::string& Employee::getLastName() const {
    return lastName;
}

int Employee::getAge() const {
    return age;
}

const std::string& Employee::getPosition() const {
    return position;
}

double Employee::getSalary() const {
    return salary;
}

void Employee::setFirstName(const std::string& fName) {
    firstName = fName;
}

void Employee::setLastName(const std::string& lName) {
    lastName = lName;
}

void Employee::setAge(int age) {
    this->age = age;
}

void Employee::setPosition(const std::string& position) {
    this->position = position;
}

void Employee::setSalary(double salary) {
    this->salary = salary;
}


