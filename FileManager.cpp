//
// Created by rolek on 04.11.2023.
//

#include "FileManager.h"

FileManager::FileManager() {}

std::vector<Employee*> FileManager::loadEmployeesFromFile(const std::string& filename) {
    std::vector<Employee*> loadedEmployees;
    std::ifstream file(filename);
    std::string line;

    if (file.is_open()) {
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string fName, lName, position, ageStr, salaryStr;

            if (std::getline(iss, fName, ',') &&
                std::getline(iss, lName, ',') &&
                std::getline(iss, position, ',') &&
                std::getline(iss, ageStr, ',') &&
                std::getline(iss, salaryStr)) {

                try {
                    int age = std::stoi(ageStr);
                    double salary = std::stod(salaryStr);

                    loadedEmployees.push_back(new Employee(fName, lName, age, position, salary));
                } catch (const std::exception& e) {
                    std::cerr << "Error converting string to number: " << e.what() << std::endl;
                    continue;
                }
            }
        }

        file.close();
    } else {
        std::cerr << "Unable to open file for reading: " << filename << std::endl;
    }

    return loadedEmployees;
}

std::vector<Client*> FileManager::loadClientsFromFile(const std::string& filename) {
    std::vector<Client*> loadedClients;
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return loadedClients;
    }

    std::string fName, lName, email, phone;
    while (file >> fName >> lName >> phone >> email) {
        loadedClients.push_back(new Client(fName, lName, phone, email));
    }

    file.close();
    return loadedClients;
}

void FileManager::ensureFileExists(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::ofstream createFile(filename);
        if (!createFile.is_open()) {
            std::cerr << "Unable to create file: " << filename << std::endl;
        }
    }
}

void FileManager::saveEmployeeToFile(const Employee* employee, const std::string& filename) {
    std::ofstream file(filename, std::ios::app);
    if (file.is_open()) {
        file << employee->getFirstName() << ","
             << employee->getLastName() << ","
             << employee->getPosition() << ","
             << employee->getAge() << ","
             << employee->getSalary() << "\n";
        file.close();
    } else {
        std::cerr << "Unable to open file for writing: " << filename << std::endl;
    }
}




