//
// Created by rolek on 30.10.2023.
//

#include "Employee.h"

Employee::Employee(std::string firstName, std::string lastName, int age, std::string position, double salary)
                    :Person(firstName, lastName, age), position(position), salary(salary){}

void Employee::displayInfo() const {
    std::cout << "Employee: " << firstName << " " << lastName << std:: endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "Position: " << position << std::endl;
    std::cout << "Salary: " << salary << std::endl << std::endl << std::endl;
}
