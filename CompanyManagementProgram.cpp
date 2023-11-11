//
// Created by rolek on 30.10.2023.
//

#include "CompanyManagementProgram.h"

CompanyManagementProgram::CompanyManagementProgram() {

}

void CompanyManagementProgram::run() {
    //displayLoginScreen();
    mainMenu();
}

void CompanyManagementProgram::displayLoginScreen() {

}

int CompanyManagementProgram::mainMenu() {
    int choice;

    do{
        std::cout << "----  MAIN MENU  ----\n\n";
        std::cout << "    1. Employees" << std::endl;
        std::cout << "    2. Clients" << std::endl;
        std::cout << "    3. EXIT" <<std::endl << std::endl;

        std::cin >> choice;

        switch(choice){
            case 1:
                employeesMenu();
                break;
            case 2:
                clientsMenu();
                break;
            case 3:
                std::cout << "See you later!\n\n";
                return(0);
                break;
            default: std::cout << "Invalid option. Try again." << std::endl;
        }
    }while(choice != 3);
}

void CompanyManagementProgram::employeesMenu() {

}

void CompanyManagementProgram::clientsMenu() {
    mainMenu();
}




