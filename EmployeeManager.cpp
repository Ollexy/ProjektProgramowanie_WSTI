#include "EmployeeManager.h"

EmployeeManager::~EmployeeManager() {
    for (Employee* e : employeesList) {
        delete e;
    }
}

void EmployeeManager::addEmployee(const std::string &fName, const std::string &lName, int age, const std::string &position, double salary) {
    Employee* newEmployee = new Employee(fName, lName, age, position, salary);
    std::cout << "\n----------------------------" << std::endl;
    std::cout << "Adding new employee";
    Sleep(500);
    std::cout << ".";
    Sleep(500);
    std::cout << ".";
    Sleep(500);
    std::cout << "." << std::endl;
    Sleep(500);
    employeesList.push_back(newEmployee);
}

void EmployeeManager::removeEmployee(Employee* emp) {
    auto it = std::find(employeesList.begin(), employeesList.end(), emp);
    if (it != employeesList.end()) {
        delete *it;
        employeesList.erase(it);
    }
}

void EmployeeManager::updateEmployeeDetails(const Employee* selectedEmployee) {
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
    std::cin.ignore();
    std::getline(std::cin, newValue);

    updateEmployee(selectedEmployee, fieldChoice, newValue);

    std::cout << "Employee details updated successfully!" << std::endl;
}

void EmployeeManager::updateEmployee(const Employee* emp, int fieldChoice, const std::string& newValue) {
    switch (fieldChoice) {
        case 1:
            const_cast<Employee*>(emp)->setFirstName(newValue);
            break;
        case 2:
            const_cast<Employee*>(emp)->setLastName(newValue);
            break;
        case 3:
            const_cast<Employee*>(emp)->setAge(std::stoi(newValue));
            break;
        case 4:
            const_cast<Employee*>(emp)->setPosition(newValue);
            break;
        case 5:
            const_cast<Employee*>(emp)->setSalary(std::stod(newValue));
            break;
        default:
            std::cout << "Invalid choice. No fields were updated." << std::endl;
            return;
    }
}

const std::vector<Employee*>& EmployeeManager::getEmployees() const {
    return employeesList;
}

void EmployeeManager::addEmployeesFromFile(const std::vector<Employee*>& employees) {
    employeesList = employees;
}

void EmployeeManager::sortAscending() {
    std::sort(employeesList.begin(), employeesList.end(), [](const Employee* a, const Employee* b) {
        return a->getLastName() < b->getLastName();
    });
}

void EmployeeManager::sortDescending() {
    std::sort(employeesList.begin(), employeesList.end(), [](const Employee* a, const Employee* b) {
        return a->getLastName() > b->getLastName();
    });
}

// Nowa metoda do wyszukiwania pracownika po nazwisku
Employee* EmployeeManager::findEmployeeByLastName(const std::string& lastName) {
    for (Employee* emp : employeesList) {
        if (emp->getLastName() == lastName) {
            return emp;
        }
    }
    return nullptr;
}
