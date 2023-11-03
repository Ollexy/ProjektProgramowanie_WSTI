//
// Created by rolek on 30.10.2023.
//

#ifndef PROJEKTPROGRAMOWANIE_WSTI_DEPARTMENT_H
#define PROJEKTPROGRAMOWANIE_WSTI_DEPARTMENT_H

#include "Employee.h"
#include <vector>

class Department {
protected:
    std::string departmentName;
    std::string localization;
    std::string manager;
    double budget;
    //std::vector<Employee*> employees;

public:
    Department(std::string xDepartmentName, std::string xLocation, std::string xManager);
    virtual ~Department() = default;
    virtual std::string getName() const = 0;

    void displayDetails() const;
    void budgetUpdate(double newBudget);
    //void addEmployee(Employee* newEmployee);
};


#endif //PROJEKTPROGRAMOWANIE_WSTI_DEPARTMENT_H
