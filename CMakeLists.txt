cmake_minimum_required(VERSION 3.26)
project(ProjektProgramowanie_WSTI)

set(CMAKE_CXX_STANDARD 17)

add_executable(ProjektProgramowanie_WSTI main.cpp
        Person.cpp
        Person.h
        Employee.cpp
        Employee.h
        Client.cpp
        Client.h
        Department.cpp
        Department.h
        FinanceDepartment.cpp
        FinanceDepartment.h
        MarketingDepartment.cpp
        MarketingDepartment.h
        CompanyManagementProgram.cpp
        CompanyManagementProgram.h
        Bin.cpp
        Bin.h
        FileManager.cpp
        FileManager.h
        EmployeeManager.cpp
        EmployeeManager.h)
