//
// Created by rolek on 14.11.2023.
//

#ifndef PROJEKTPROGRAMOWANIE_WSTI_EMPLOYEEMANAGER_H
#define PROJEKTPROGRAMOWANIE_WSTI_EMPLOYEEMANAGER_H

#include "Employee.h"
#include <windows.h>
#include <vector>
#include <iostream>
#include <algorithm>

class EmployeeManager {
private:
    std::vector<Employee*> employeesList;

public:
    EmployeeManager() = default;
    ~EmployeeManager();

    void addEmployee(const std::string &fName, const std::string &lName, int age, const std::string &position, double salary);
    void removeEmployee(Employee *emp);
    void updateEmployeeDetails(const Employee* selectedEmployee);
    void updateEmployee(const Employee* emp, int fieldChoice, const std::string& newValue);
    const std::vector<Employee*>& getEmployees() const;
    void addEmployeesFromFile(const std::vector<Employee*>& employees);

    void sortAscending();
    void sortDescending();

    Employee* findEmployeeByLastName(const std::string& lastName);
};

#endif


