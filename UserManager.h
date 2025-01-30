//
// Created by rolek on 09.01.2025.
//

#ifndef PROJEKTPROGRAMOWANIE_WSTI_USERMANAGER_H
#define PROJEKTPROGRAMOWANIE_WSTI_USERMANAGER_H

#include <string>
#include <vector>
#include "User.h"

class UserManager {
public:
    UserManager();  // Konstruktor
    bool authenticate(const std::string& login, const std::string& password) const;
    User* getUserByUsername(const std::string& username);
    std::string getRole(const std::string& login) const;

private:
    std::vector<User*> users;
};


#endif
