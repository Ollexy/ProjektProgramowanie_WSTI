//
// Created by rolek on 30.10.2023.
//

#ifndef PROJEKTPROGRAMOWANIE_WSTI_EMPLOYEE_H
#define PROJEKTPROGRAMOWANIE_WSTI_EMPLOYEE_H

#include <string>
#include <iostream>
#include "Person.h"


class Employee : public Person {
private:
    std::string position;
    double salary;

public:
    Employee(std::string firstName, std::string lastName, int age, std::string position, double salary);

    std::string getFirstName() const { return firstName; }
    std::string getLastName() const { return lastName; }
    std::string getPosition() const { return position; }
    double getSalary() const { return salary; }
    int getAge() const { return age; }

    void setFirstName(const std::string& fName) { firstName = fName; }
    void setLastName(const std::string& lName) { lastName = lName; }
    void setPosition(const std::string& xPosition) { position = xPosition; }
    void setSalary(double xSalary) { salary = xSalary; }
    void setAge(int xAge) { age = xAge; }

    void displayInfo() const override;
};


#endif //PROJEKTPROGRAMOWANIE_WSTI_EMPLOYEE_H
