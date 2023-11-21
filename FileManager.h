//
// Created by rolek on 04.11.2023.
//

#ifndef PROJEKTPROGRAMOWANIE_WSTI_FILEMANAGER_H
#define PROJEKTPROGRAMOWANIE_WSTI_FILEMANAGER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "Employee.h"
#include "Client.h"
#include "Bin.h"

class FileManager {
public:
    FileManager();

    void ensureFileExists(const std::string& filename);
    void saveEmployeesToFile(const std::vector<Employee*>& employees, const std::string& filename);
    std::vector<Employee*> loadEmployeesFromFile(const std::string& filename);
};


#endif //PROJEKTPROGRAMOWANIE_WSTI_FILEMANAGER_H
