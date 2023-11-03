//
// Created by rolek on 30.10.2023.
//

#ifndef PROJEKTPROGRAMOWANIE_WSTI_EMPLOYEE_H
#define PROJEKTPROGRAMOWANIE_WSTI_EMPLOYEE_H

#include "Person.h"
#include "Department.h"

class Employee : public Person {
private:
    std::string position;
    double salary;
    //Department* department;

public:
    //Employee(std::string fName, std::string lName, int xAge, std::string xPosisiton, double xSalary, Department* xDepartment);

    void displayInfo() const override;
};


#endif //PROJEKTPROGRAMOWANIE_WSTI_EMPLOYEE_H
