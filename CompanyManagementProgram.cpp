#include "CompanyManagementProgram.h"
#include <iostream>

CompanyManagementProgram::CompanyManagementProgram(std::vector<Employee*>& employees, std::vector<Client*>& clients)
        : employees(employees), clients(clients) {}

CompanyManagementProgram::~CompanyManagementProgram() {
    for (Employee* emp : employees) {
        delete emp;
    }
    for (Client* cli : clients) {
        delete cli;
    }
}

void CompanyManagementProgram::run() {
    UserManager userManager;

    std::string username, password;
    int attempts = 0;

    while (attempts < 3) {
        std::cout << "LOGIN: ";
        std::cin >> username;
        std::cout << "PASSWORD: ";
        std::cin >> password;

        if (userManager.authenticate(username, password)) {
            User* user = userManager.getUserByUsername(username);

            system("cls");
            std::cout << "\nLogin successful!\n" << std::endl;
            std::string role = userManager.getRole(username);

            if (role == "admin") {
                std::cout << "Welcome, Admin!\n" << std::endl;
                adminMenu();
            } else if (role == "user") {
                std::cout << "\nWelcome, User!\n" << std::endl;
                userMenu();
            }

            break;  // Zakończ pętlę po zalogowaniu
        } else {
            attempts++;
            std::cout << "Invalid login or password. Try again." << std::endl;
        }
    }

    if (attempts == 3) {
        std::cout << "Too many failed login attempts. Exiting program." << std::endl;
    }
}

void CompanyManagementProgram::adminMenu() {
    int choice;
    do {
        std::cout << "\n=== Admin Menu ===\n";
        std::cout << "1. Add Employee\n";
        std::cout << "2. Remove Employee\n";
        std::cout << "3. View Employees\n";
        std::cout << "4. Sort Employees (Ascending)\n";
        std::cout << "5. Sort Employees (Descending)\n";
        std::cout << "6. Add Client\n";
        std::cout << "7. Remove Client\n";
        std::cout << "8. View Clients\n";
        std::cout << "9. Exit\n\n";
        std::cout << "-> ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                system("cls");
                std::string fName, lName, position;
                int age;
                double salary;
                std::cout << "Enter first name: ";
                std::cin >> fName;
                std::cout << "Enter last name: ";
                std::cin >> lName;
                std::cout << "Enter age: ";
                std::cin >> age;
                std::cout << "Enter position: ";
                std::cin >> position;
                std::cout << "Enter salary: ";
                std::cin >> salary;

                employeeManager.addEmployee(fName, lName, age, position, salary);
                std::cout << "Employee added successfully!\n";
                Sleep(500);
                system("cls");
                break;
            }
            case 2: {
                system("cls");
                std::string lastName;
                std::cout << "Enter the last name of the employee to remove: ";
                std::cin >> lastName;
                Employee* emp = employeeManager.findEmployeeByLastName(lastName);
                if (emp) {
                    employeeManager.removeEmployee(emp);
                    std::cout << "Employee removed.\n";
                } else {
                    std::cout << "Employee not found.\n";
                }
                break;
            }
            case 3:
                system("cls");
                displayEmployees();
                break;
            case 4:
                system("cls");
                employeeManager.sortAscending();
                std::cout << "Employees sorted in ascending order.\n";
                break;
            case 5:
                system("cls");
                employeeManager.sortDescending();
                std::cout << "Employees sorted in descending order.\n";
                break;
            case 6: {
                system("cls");
                std::string fName, lName, email, phone;
                std::cout << "Enter first name: ";
                std::cin >> fName;
                std::cout << "Enter last name: ";
                std::cin >> lName;
                std::cout << "Enter email: ";
                std::cin >> email;
                std::cout << "Enter phone: ";
                std::cin >> phone;

                clientManager.addClient(fName, lName, email, phone);
                std::cout << "Client added successfully!\n";
                break;
            }
            case 7: {
                system("cls");
                std::string lastName;
                std::cout << "Enter the last name of the client to remove: ";
                std::cin >> lastName;
                Client* cli = clientManager.findClientByLastName(lastName);
                if (cli) {
                    clientManager.removeClient(cli);
                    std::cout << "Client removed.\n";
                } else {
                    std::cout << "Client not found.\n";
                }
                break;
            }
            case 8:
                system("cls");
                displayClients();
                break;
            case 9:
                system("cls");
                std::cout << "Exiting program...\n";
                break;
            default:
                std::cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 9);
}

void CompanyManagementProgram::userMenu() {
    int choice;
    do {
        std::cout << "\n=== User Menu ===\n";
        std::cout << "1. View Employees\n";
        std::cout << "2. View Clients\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                displayEmployees();
                break;
            case 2:
                displayClients();
                break;
            case 3:
                std::cout << "Exiting program...\n";
                break;
            default:
                std::cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 3);
}

void CompanyManagementProgram::displayEmployees() {
    std::cout << "\n=== Employees List ===\n";
    const std::vector<Employee*>& employees = employeeManager.getEmployees();
    for (const Employee* emp : employees) {
        std::cout << emp->getFirstName() << " " << emp->getLastName()
                  << ", Age: " << emp->getAge()
                  << ", Position: " << emp->getPosition()
                  << ", Salary: " << emp->getSalary() << "\n";
    }
}

void CompanyManagementProgram::displayClients() {
    std::cout << "\n=== Clients List ===\n";
    const std::vector<Client*>& clients = clientManager.getClients();
    for (const Client* cli : clients) {
        std::cout << cli->getFirstName() << " " << cli->getLastName()
                  << ", Email: " << cli->getEmail()
                  << ", Phone: " << cli->getPhone() << "\n";
    }
}
