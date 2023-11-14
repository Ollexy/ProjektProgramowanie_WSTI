//
// Created by rolek on 14.11.2023.
//

#ifndef PROJEKTPROGRAMOWANIE_WSTI_EMPLOYEEMANAGER_H
#define PROJEKTPROGRAMOWANIE_WSTI_EMPLOYEEMANAGER_H

#include <vector>
#include <algorithm>
#include "Employee.h"

class EmployeeManager {
private:
    std::vector<Employee*> employees;

public:
    EmployeeManager() = default;
    ~EmployeeManager();     //free space after removing employee

    void addEmployee(const std::string& fName, const std::string& lName, int age, const std::string& position, double salary, Department* department);
    void removeEmployee(Employee* emp);
    void updateEmployee(Employee* emp, const std::string& field, const std::string& value);
};


#endif //PROJEKTPROGRAMOWANIE_WSTI_EMPLOYEEMANAGER_H
