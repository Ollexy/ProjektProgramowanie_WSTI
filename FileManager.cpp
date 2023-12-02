//
// Created by rolek on 04.11.2023.
//

#include "FileManager.h"

FileManager::FileManager() {}

std::vector<Employee *> FileManager::loadEmployeesFromFile(const std::string &filename) {
    std::vector<Employee *> loadedEmployees;
    std::ifstream file(filename);
    std::string line;

    if (file.is_open()) {
        file.seekg(0, std::ios::beg); //cofanie kursora na początek pliku

        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string fName, lName, position, ageStr, salaryStr;

            if (std::getline(iss, fName, ',') &&
                std::getline(iss, lName, ',') &&
                std::getline(iss, position, ',') &&
                std::getline(iss, ageStr, ',') &&
                std::getline(iss, salaryStr)) {

                // Konwersja ageStr i salaryStr na odpowiednie typy
                try {
                    int age = std::stoi(ageStr);
                    double salary = std::stod(salaryStr);

                    // make employee and add it to vector
                    loadedEmployees.push_back(new Employee(fName, lName, age, position, salary));

                } catch (const std::exception &e) {
                    std::cerr << "Error converting string to number: " << e.what() << std::endl;
                    continue;
                }
            } else {
                std::cerr << "Error reading line from file: " << line << std::endl;
            }
        }

        file.close();
    } else {
        std::cerr << "Unable to open file for reading: " << filename << std::endl;
    }

    return loadedEmployees;
}

void FileManager::ensureFileExists(const std::string &filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::ofstream createFile(filename);
        if (!createFile.is_open()) {
            std::cerr << "Unable to create file: " << filename << std::endl;
        }
    }
}

void FileManager::saveEmployeeToFile(const Employee *employee, const std::string &filename) {
    std::ofstream file(filename, std::ios::app);  // otwieranie pliku w trybie append (dopisywania na koniec pliku)

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