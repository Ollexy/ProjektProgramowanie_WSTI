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

    void displayInfo() const override;
};


#endif //PROJEKTPROGRAMOWANIE_WSTI_EMPLOYEE_H
