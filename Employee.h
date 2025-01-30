//
// Created by rolek on 30.10.2023.
//

#ifndef PROJEKTPROGRAMOWANIE_WSTI_EMPLOYEE_H
#define PROJEKTPROGRAMOWANIE_WSTI_EMPLOYEE_H

#include <string>

class Employee {
private:
    std::string firstName;
    std::string lastName;
    int age;
    std::string position;
    double salary;

public:
    Employee(const std::string &fName, const std::string &lName, int age, const std::string &position, double salary);

    // Gettery
    const std::string& getFirstName() const;
    const std::string& getLastName() const;
    int getAge() const;
    const std::string& getPosition() const;
    double getSalary() const;

    // Settery
    void setFirstName(const std::string& fName);
    void setLastName(const std::string& lName);
    void setAge(int age);
    void setPosition(const std::string& position);
    void setSalary(double salary);
};

#endif

