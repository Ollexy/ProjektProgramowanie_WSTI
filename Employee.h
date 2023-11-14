//
// Created by rolek on 30.10.2023.
//

#ifndef PROJEKTPROGRAMOWANIE_WSTI_EMPLOYEE_H
#define PROJEKTPROGRAMOWANIE_WSTI_EMPLOYEE_H

#include "Department.h"
#include "Person.h"
#include <string>
#include <iostream>

class Department;

class Employee : public Person {
private:
    std::string position;
    double salary;
    Department* department;

public:
    Employee(std::string firstName, std::string lastName, int age, std::string posisiton, double salary, Department* department);

    std::string getFirstName() const { return firstName; }
    std::string getLastName() const { return lastName; }
    int getAge() const { return age; }
    std::string getPosition() const { return position; }
    double getSalary() const { return salary; }
    Department* getDepartment() const { return department; }

    void setFirstName(const std::string& fName) { firstName = fName; }
    void setLastName(const std::string& lName) { lastName = lName; }
    void setAge(int xAge) { age = xAge; }
    void setPosition(const std::string& xPosition) { position = xPosition; }
    void setSalary(double xSalary) { salary = xSalary; }
    void setDepartment(Department* xDepartment) { department = xDepartment; }

    void displayInfo() const override;
};


#endif //PROJEKTPROGRAMOWANIE_WSTI_EMPLOYEE_H
