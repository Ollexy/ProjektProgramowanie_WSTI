//
// Created by rolek on 04.11.2023.
//

#ifndef PROJEKTPROGRAMOWANIE_WSTI_FILEMANAGER_H
#define PROJEKTPROGRAMOWANIE_WSTI_FILEMANAGER_H

#include "Employee.h"
#include "Client.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>


class FileManager {
public:
    FileManager();

    void ensureFileExists(const std::string& filename);
    void saveEmployeeToFile(const Employee* employee, const std::string& filename);
    std::vector<Employee*> loadEmployeesFromFile(const std::string& filename);
    std::vector<Client*> loadClientsFromFile(const std::string& filename);
};

#endif



