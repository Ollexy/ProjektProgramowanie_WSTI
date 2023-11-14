//
// Created by rolek on 14.11.2023.
//

#include "EmployeeManager.h"

EmployeeManager::~EmployeeManager() {
    for(Employee* e: employees){
        delete e;
    }

}

void
EmployeeManager::addEmployee(const std::string &fName, const std::string &lName, int age, const std::string &position,
                             double salary, Department *department) {

    Employee* newEmployee = new Employee(fName, lName, age, position, salary, department);
    employees.push_back(newEmployee);
}

void EmployeeManager::removeEmployee(Employee *emp) {
    auto it = std::find(employees.begin(), employees.end(), emp);
    if(it != employees.end()){
        delete *it;
        employees.erase(it);
    }


}

void EmployeeManager::updateEmployee(Employee *emp, const std::string &field, const std::string &value) {
    auto it = std::find(employees.begin(), employees.end(), emp);
    if (it != employees.end()) {
        if (field == "firstName") {
            (*it)->setFirstName(value);
        } else if (field == "lastName") {
            (*it)->setLastName(value);
        } else if (field == "age") {
            // Tutaj można dodać dodatkową logikę walidacji dla pola "age"
            (*it)->setAge(std::stoi(value));
        } else if (field == "position") {
            (*it)->setPosition(value);
        } else if (field == "salary") {
            // Tutaj można dodać dodatkową logikę walidacji dla pola "salary"
            (*it)->setSalary(std::stod(value));
        } else if (field == "department") {
            // Tutaj można dodać dodatkową logikę walidacji dla pola "department"
            // (*it)->setDepartment(value);
        } else {
            // Obsługa błędu - nieznane pole
            std::cerr << "Error: Unknown field " << field << std::endl;
        }
    }
}
