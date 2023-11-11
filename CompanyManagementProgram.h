#ifndef PROJEKTPROGRAMOWANIE_WSTI_COMPANYMANAGEMENTPROGRAM_H
#define PROJEKTPROGRAMOWANIE_WSTI_COMPANYMANAGEMENTPROGRAM_H

#include "Person.h"
#include "Employee.h"
#include "Client.h"
#include "Department.h"
#include "ITDepartment.h"
#include "HRDepartment.h"
#include "MarketingDepartment.h"
#include "FinanceDepartment.h"
#include "Bin.h"
#include "CompanyManagementProgram.h"
#include "FileManager.h"
#include <iostream>
#include <fstream>

class CompanyManagementProgram {
private:
    std::vector<Employee> employees;
    std::vector<Client> clients;
    Bin bin;
    FileManager fileManager;

public:
    CompanyManagementProgram();

    void start();
    void mainMenu();
    void secondaryMenu();
    void displayMenu();
    void displayLoginScreen();

    void addEmployee();
    void removeEmployee();
    void updateEmployeeDetails();
    void displayEmloyees();
    void sortEmployees();

    void addClient();
    void removeClient();
    void updateClientDetails();
    void displayClients();
    void sortClients();

    void saveData();
    void loadData();
};


#endif //PROJEKTPROGRAMOWANIE_WSTI_COMPANYMANAGEMENTPROGRAM_H

