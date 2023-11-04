//
// Created by rolek on 30.10.2023.
//

#include "Employee.h"

Employee::Employee(std::string firstName, std::string lastName, int age, std::string posisiton, double salary,
                   Department *department)
                    :Person(firstName, lastName, age), position(position), salary(salary), department(department){}

void Employee::displayInfo() const {
    std::cout << "Employee: " << firstName << " " << lastName << std:: endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "Position: " << position << std::endl;
    std::cout << "Department " << department->getName() << std::endl;
    std::cout << "Salary: " << salary << std::endl << std::endl << std::endl;
}
