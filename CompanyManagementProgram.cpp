//
// Created by rolek on 30.10.2023.
//

#include "CompanyManagementProgram.h"

CompanyManagementProgram::CompanyManagementProgram()
    :employeeManager(), employees(){}

CompanyManagementProgram::CompanyManagementProgram(std::vector<Employee *> &employees)
        :employeeManager(), employees(employees){}

void CompanyManagementProgram::displayLoginScreen() {
    std::string username, password;

    std::cout << "          WELCOME TO XYZ COMPANY\n\n";

    std::cout << "            username:";
    std::cin >> username;

    std::cout << "            password:";
    std::cin >> password;

    std::cout << std::endl;

    if(login(username, password)){
        std::cout << "      Login succesfull!\n";
        isLoggedIn = true;
        Sleep(2000);
        system("cls");
    }
}

bool CompanyManagementProgram::login(const std::string &username, const std::string &password) {
    auto userIt = users.find(username);

    if(userIt != users.end()){
        return userIt->second == password;
    }

    return false;
}

void CompanyManagementProgram::run() {
    std::string filename = "employees.txt";

    fileManager.ensureFileExists(filename);

    std::vector<Employee *> loadedEmployees = fileManager.loadEmployeesFromFile("employees.txt");
    employeeManager.addEmployeesFromFile(loadedEmployees);

    while (true) {
        if (!isLoggedIn) {
            displayLoginScreen();
        } else {
            employees = fileManager.loadEmployeesFromFile("employees.txt");
            mainMenu();
        }
    }
}

void CompanyManagementProgram::mainMenu() {
    system("cls");
    char choice;

    do {
        std::cout << "----  MAIN MENU  ----" << std::endl << std::endl;
        std::cout << "1. Employee Menu" << std::endl;
        std::cout << "2. Client Menu" << std::endl;
        std::cout << "0. EXIT" << std::endl << std::endl;

        std::cin >> choice;

        switch (choice) {
            case '1':
                employeesMenu();
                break;
            case '2':
                clientsMenu();
                break;
            case '0':
                std::cout << "See you later!";
                Sleep(3000);
                exit(0);
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != '1' && choice != '2' && choice != '0');
}

void CompanyManagementProgram::employeesMenu() {
    system("cls");
    char choice;

    do{
        std::cout << "\n----  EMPLOYEE MENU  ----" << std::endl << std::endl;
        std::cout << "1. Display employees" << std::endl;
        std::cout << "2. Add employee" << std::endl;
        std::cout << "3. Remove employee" << std::endl;
        std::cout << "4. Update employee information" << std::endl;
        std::cout << "5. Sort employees" << std::endl;
        std::cout << "0. Back to Main Menu" << std::endl;

        std::cin >> choice;
        switch (choice) {
            case '1':
                displayEmployees();
                break;
            case '2':
                addEmployee();
                break;
            case '3':
                removeEmployee();
                break;
            case '4':
                updateEmployeeDetails();
                break;
            case '5':
                sortEmployees();
                break;
            case '0':
                mainMenu();
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }while(choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '5');
}

void CompanyManagementProgram::clientsMenu() {
    char choice;

    do {
        std::cout << "----  CLIENT MENU  ----" << std::endl;
        std::cout << "1. Display Clients" << std::endl;
        std::cout << "2. Add Client" << std::endl;
        std::cout << "3. Remove Client" << std::endl;
        std::cout << "4. Back to Main Menu" << std::endl;

        std::cin >> choice;
        switch (choice) {
            case '1':
                // TODO
                break;
            case '2':
                // TODO
                break;
            case '3':
                // TODO
                break;
            case '4':
                mainMenu();
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }while(choice != '1' && choice != '2' && choice != '3' && choice != '4');
}

void CompanyManagementProgram::addEmployee() {
    std::string fName, lName, position;
    int age;
    double salary;

    std::cout << "Enter first name: ";
    std::cin >> fName;

    std::cout << "Enter last name: ";
    std::cin.ignore(); // ignor new line sign from previous cin
    std::getline(std::cin, lName);

    std::cout << "Enter age: ";
    std::cin >> age;

    std::cout << "Enter position: ";
    std::cin.ignore();
    std::getline(std::cin, position);

    std::cout << "Enter salary: ";
    std::cin.ignore();
    std::cin >> salary;

    employeeManager.addEmployee(fName, lName, age, position, salary);

    std::cout << "\n----------------------------" << std::endl;
    std::cout << "Adding new employee";
    Sleep(500);
    std::cout << ".";
    Sleep(500);
    std::cout << ".";
    Sleep(500);
    std::cout << "." << std::endl;
    Sleep(500);

    if (employeeManager.getEmployees().empty()) {
        std::cout << "SOMETHING IS NOT WORKING. I COULDN'T ADD NEW EMPLOYEE" << std::endl;
    } else {
        std::cout << "Employee added successfully!" << std::endl << std::endl;
        std::cout << "Press any key to continue";
        system("pause");
    }
    saveData(); //adding employee to file automaticly
}

void CompanyManagementProgram::removeEmployee() {
    displayEmployees();

    int choice;
    std::cout << "Enter the number of the employee to remove (0 to cancel): ";
    std::cin >> choice;

    if (choice >= 1 && static_cast<size_t>(choice) <= employeeManager.getEmployees().size()) {
        const auto& selectedEmployee = employeeManager.getEmployees()[choice - 1];

        displayEmployeeDetails(selectedEmployee);

        char confirmation;
        std::cout << "Do you really want to remove this employee? (y/n): ";
        std::cin >> confirmation;

        if (confirmation == std::toupper('y')) {
            employeeManager.removeEmployee(selectedEmployee);

            std::cout << "Employee removed successfully!" << std::endl;

            saveData();
        } else {
            std::cout << "Employee removal canceled." << std::endl;
        }
    } else if (choice != 0) {
        std::cout << "Invalid choice. Please try again." << std::endl;
    }
}

void CompanyManagementProgram::updateEmployeeDetails() {
    std::cout << "----  UPDATE EMPLOYEE DETAILS  ----" << std::endl;

    displayEmployees();

    std::cout << "Enter the number of the employee to update details (0 to go back): ";
    int choice;
    std::cin >> choice;

    if (choice >= 1 && static_cast<size_t>(choice) <= employeeManager.getEmployees().size()) {
        const auto& selectedEmployee = employeeManager.getEmployees()[choice - 1];

        employeeManager.updateEmployeeDetails(selectedEmployee);
    } else if (choice != 0) {
        std::cout << "Invalid choice. Please try again." << std::endl;
    }
}

void CompanyManagementProgram::displayEmployees() {
    system("cls");

    const auto &employeesList = employeeManager.getEmployees();

    if (employeesList.empty()) {
        std::cout << "There are no employees! Returning to the employee menu." << std::endl;
        return; // return to employee menu
    }


    std::cout << "----  EMPLOYEE LIST  ----" << std::endl << std::endl;

    for (size_t i = 0; i < employeesList.size(); ++i) {
        const auto &employee = employeesList[i];
        std::cout << i + 1 << ". " << employee->getFirstName() << " " << employee->getLastName()
                  << ", Position: " << employee->getPosition() << std::endl;
    }

    std::cout << std::endl << "-------------------------" << std::endl << std::endl;

    std::cout << std::endl << "Enter the number of the employee to view details (0 to go back): ";
    int choice;
    std::cin >> choice;

    if (choice >= 1 && static_cast<size_t>(choice) <= employeesList.size()) {
        system("cls");

        const auto &selectedEmployee = employeesList[choice - 1];
        displayEmployeeDetails(selectedEmployee);

        system("pause");
    } else if (choice != 0) {
        std::cout << "Invalid choice. Please try again." << std::endl;
    }
}

void CompanyManagementProgram::displayEmployeeDetails(const Employee *employee) {
    std::cout << "----  EMPLOYEE DETAILS  ----" << std::endl;
    std::cout << "Name: " << employee->getFirstName() << " " << employee->getLastName() << std::endl;
    std::cout << "Age: " << employee->getAge() << std::endl;
    std::cout << "Position: " << employee->getPosition() << std::endl;
    std::cout << "Salary: " << employee->getSalary() << std::endl << std::endl;
}

void CompanyManagementProgram::saveData() {
    std::string filename = "employees.txt";

    for (const auto &employee : employeeManager.getEmployees()) {
        fileManager.saveEmployeeToFile(employee, filename);
    }

    std::cout << "Employee data saved successfully." << std::endl;
}

void CompanyManagementProgram::sortEmployees() {
    char choice;

    do {
        std::cout << "----  SORT EMPLOYEES MENU  ----" << std::endl << std::endl;
        std::cout << "1. Sort Alphabetically" << std::endl;
        std::cout << "2. Sort Reverse Alphabetically" << std::endl;
        std::cout << "0. Back to Employee Menu" << std::endl;

        std::cin >> choice;

        switch (choice) {
            case '1':
                employeeManager.sortAscending();
                std::cout << "Employees sorted alphabetically." << std::endl;
                break;
            case '2':
                employeeManager.sortDescending();
                std::cout << "Employees sorted in reverse alphabetical order." << std::endl;
                break;
            case '0':
                employeesMenu();
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != '1' && choice != '2' && choice != '0');
}



