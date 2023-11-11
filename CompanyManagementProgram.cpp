//
// Created by rolek on 30.10.2023.
//

#include "CompanyManagementProgram.h"

CompanyManagementProgram::CompanyManagementProgram() {

}

void CompanyManagementProgram::displayLoginScreen() {
    std::string username, password;

    std::cout << "          WELCOME TO XYZ COMPANY\n\n";

    std::cout << "            username:";
    std::cin >> username;
    std::cout << "            password:";

    char ch;
    while ((ch = getKeyPress(true)) != 13) {
        password.push_back(ch);
    }
    std::cout << std::endl <<std::endl;

    if(login(username, password)){
        std::cout << "Login succesfull!";
        isLoggedIn = true;
    }
}

bool CompanyManagementProgram::login(const std::string &username, const std::string &password) {
    auto userIt = users.find(username);

    if(userIt != users.end()){
        return userIt->second == password;
    }

    return false;
}

char CompanyManagementProgram::getKeyPress(bool maskInput) {
    char ch = _getch();
    if (maskInput) {

    }
        return ch;
}

void CompanyManagementProgram::clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void CompanyManagementProgram::run() {
    mainMenu();
//    while (true) {
//        if (!isLoggedIn) {
//            displayLoginScreen();
//        } else {
//            mainMenu();
//        }
//    }
}

void CompanyManagementProgram::mainMenu() {
    char choice;

    do {
        std::cout << "----  MAIN MENU  ----" << std::endl;
        std::cout << "1. Employee Menu" << std::endl;
        std::cout << "2. Client Menu" << std::endl;
        std::cout << "3. EXIT" << std::endl << std::endl;

        std::cout << "Enter your choice: ";
        choice = getKeyPress(choice);
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case '1':
                employeesMenu();
                break;
            case '2':
                clientsMenu();
                break;
            case '3':
                std::cout << "See you later!";
                Sleep(3000);
                exit(0);
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != '1' && choice != '2' && choice != '3');
}

void CompanyManagementProgram::employeesMenu() {

}

void CompanyManagementProgram::clientsMenu() {
    mainMenu();
}






