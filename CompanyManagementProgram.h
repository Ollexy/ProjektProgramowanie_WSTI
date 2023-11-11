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
#include <unordered_map>
#include <conio.h>
#include <cstdlib>
#include <windows.h>

class CompanyManagementProgram {
private:
    std::vector<Employee> employees;
    std::vector<Client> clients;
    Bin bin;
    FileManager fileManager;
    std::unordered_map<std::string,std::string> users{{"admin","admin"}, {"user", "user"}};
    bool isLoggedIn = false;

    void displayLoginScreen();
    bool login(const std::string& username, const std::string& password);
    char getKeyPress();
    void clearInputBuffer();

public:
    CompanyManagementProgram();

    void run();

    void mainMenu();

    void employeesMenu();
    void addEmployee();
    void removeEmployee();
    void updateEmployeeDetails();
    void displayEmloyees();
    void sortEmployees();

    void clientsMenu();
    void addClient();
    void removeClient();
    void updateClientDetails();
    void displayClients();
    void sortClients();

    void saveData();
    void loadData();
};


#endif //PROJEKTPROGRAMOWANIE_WSTI_COMPANYMANAGEMENTPROGRAM_H

