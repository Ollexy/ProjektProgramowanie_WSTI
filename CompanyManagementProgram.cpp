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
        system("CLS");
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

    while (true) {
        if (!isLoggedIn) {
            displayLoginScreen();
        } else {
            mainMenu();
        }
    }
}

void CompanyManagementProgram::mainMenu() {
    char choice;

    do {
        std::cout << "----  MAIN MENU  ----" << std::endl << std::endl;
        std::cout << "1. Employee Menu" << std::endl;
        std::cout << "2. Client Menu" << std::endl;
        std::cout << "3. Save data" << std::endl;
        std::cout << "0. EXIT" << std::endl << std::endl;

        std::cin >> choice;

        switch (choice) {
            case '1':
                employeesMenu();
                break;
            case '2':
                clientsMenu();
                break;
            case '3':
                saveData();
                break;
            case '0':
                std::cout << "See you later!";
                Sleep(3000);
                exit(0);
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != '1' && choice != '2' && choice != '3' && choice != '0');
}

void CompanyManagementProgram::employeesMenu() {
    char choice;

    do{
        std::cout << "\n----  EMPLOYEE MENU  ----" << std::endl << std::endl;
        std::cout << "1. Display employees" << std::endl;
        std::cout << "2. Add employee" << std::endl;
        std::cout << "3. Remove employee" << std::endl;
        std::cout << "4. Update employee information" << std::endl;
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
                //removeEmployee();
                break;
            case '4':
                updateEmployeeDetails();
                break;
            case '0':
                mainMenu();
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }while(choice != '1' && choice != '2' && choice != '3' && choice != '4');
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
    }while(choice != '1' && choice != '2' && choice != '3');
}

void CompanyManagementProgram::addEmployee() {
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

    std::cout << "\n----------------------------" << std::endl;
    std::cout << "Adding new employee";
    Sleep(500);
    std::cout << ".";
    Sleep(500);
    std::cout << ".";
    Sleep(500);
    std::cout << "." << std::endl;
    Sleep(500);

    employeeManager.addEmployee(fName, lName, age, position, salary);

    if(employeeManager.getEmployees().empty()){
        std::cout << "SOMETHING IS NOT WORKING. I COULDN'T ADD NEW EMPLOYEE" << std::endl;
    }
    else{
        std::cout << "Employee added successfully!" << std::endl << std::endl;
    }
}

void CompanyManagementProgram::removeEmployee() {

}

void CompanyManagementProgram::updateEmployeeDetails() {
    std::cout << "----  UPDATE EMPLOYEE DETAILS  ----" << std::endl;

    displayEmployees();

    std::cout << "Enter the number of the employee to update details (0 to go back): ";
    int choice;
    std::cin >> choice;

    if (choice >= 1 && static_cast<size_t>(choice) <= employeeManager.getEmployees().size()) {
        const auto& selectedEmployee = employeeManager.getEmployees()[choice - 1];

        std::cout << "Select the field to update:" << std::endl;
        std::cout << "1. First Name" << std::endl;
        std::cout << "2. Last Name" << std::endl;
        std::cout << "3. Age" << std::endl;
        std::cout << "4. Position" << std::endl;
        std::cout << "5. Salary" << std::endl;

        int fieldChoice;
        std::cin >> fieldChoice;

        std::string newValue;
        std::cout << "Enter the new value: ";
        std::cin >> newValue;

        switch (fieldChoice) {
            case 1:
                selectedEmployee->setFirstName(newValue);
                break;
            case 2:
                selectedEmployee->setLastName(newValue);
                break;
            case 3:
                selectedEmployee->setAge(std::stoi(newValue));
                break;
            case 4:
                selectedEmployee->setPosition(newValue);
                break;
            case 5:
                selectedEmployee->setSalary(std::stod(newValue));
                break;
            default:
                std::cout << "Invalid choice. No fields were updated." << std::endl;
                return;
        }
        std::cout << "Employee details updated successfully!" << std::endl << std::endl;
    } else if (choice != 0) {
        std::cout << "Invalid choice. Please try again." << std::endl;
    }
}

void CompanyManagementProgram::displayEmployees() {
    if(employeeManager.getEmployees().empty()){
        std::cout << "There is no employees! I will sent you back to employee menu";
        employeesMenu();
    }
    std::cout << "----  EMPLOYEE LIST  ----" << std::endl;
    auto employeesList = employeeManager.getEmployees();

    for (size_t i = 0; i < employeesList.size(); ++i) {
        const auto& employee = employeesList[i];
        std::cout << i + 1 << ". " << employee->getFirstName() << " " << employee->getLastName() << std::endl << std::endl;
    }

    std::cout << "Enter the number of the employee to view details (0 to go back): ";
    int choice;
    std::cin >> choice;

    if (choice >= 1 && static_cast<size_t>(choice) <= employeesList.size()) {
        const auto& selectedEmployee = employeesList[choice - 1];
        displayEmployeeDetails(selectedEmployee);
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
    fileManager.saveEmployeesToFile(employeeManager.getEmployees(), filename);
    std::cout << "Employee data saved successfully." << std::endl;
}








