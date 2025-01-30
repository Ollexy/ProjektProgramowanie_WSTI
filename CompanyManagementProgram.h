#ifndef PROJEKTPROGRAMOWANIE_WSTI_COMPANYMANAGEMENTPROGRAM_H
#define PROJEKTPROGRAMOWANIE_WSTI_COMPANYMANAGEMENTPROGRAM_H

#include "Employee.h"
#include "Client.h"
#include "EmployeeManager.h"
#include "ClientManager.h"
#include "UserManager.h"
#include <vector>


class CompanyManagementProgram {
private:
    std::vector<Employee*>& employees;
    std::vector<Client*>& clients;
    EmployeeManager employeeManager;
    ClientManager clientManager;

    void adminMenu();
    void userMenu();
    void displayEmployees();
    void displayClients();

public:
    CompanyManagementProgram(std::vector<Employee*>& employees, std::vector<Client*>& clients);
    ~CompanyManagementProgram();

    void run();  // Uruchomienie programu
};

#endif



