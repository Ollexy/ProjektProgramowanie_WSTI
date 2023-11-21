#ifndef PROJEKTPROGRAMOWANIE_WSTI_COMPANYMANAGEMENTPROGRAM_H
#define PROJEKTPROGRAMOWANIE_WSTI_COMPANYMANAGEMENTPROGRAM_H

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <conio.h>
#include <cstdlib>
#include <windows.h>
#include "Person.h"
#include "Employee.h"
#include "Client.h"
#include "Bin.h"
#include "CompanyManagementProgram.h"
#include "FileManager.h"
#include "EmployeeManager.h"


class EmployeeManager;

class CompanyManagementProgram {
private:
    EmployeeManager employeeManager;
    std::vector<Employee*> employees;
    std::vector<Client> clients;
    Bin bin;
    FileManager fileManager;
    std::unordered_map<std::string,std::string> users{{"admin","admin"}, {"user", "user"}};
    bool isLoggedIn = false;

    void displayLoginScreen();
    bool login(const std::string& username, const std::string& password);

public:
    CompanyManagementProgram();
    CompanyManagementProgram(std::vector<Employee*>& employees);

    void run();
    void mainMenu();

    void employeesMenu();
    void addEmployee();
    void removeEmployee();
    void updateEmployeeDetails();
    void displayEmployees();
    void displayEmployeeDetails(const Employee* employee);
    void sortEmployees();

    void clientsMenu();
    void addClient();
    void removeClient();
    void updateClientDetails();
    void displayClients();
    void sortClients();

    void saveData();
};


#endif //PROJEKTPROGRAMOWANIE_WSTI_COMPANYMANAGEMENTPROGRAM_H

