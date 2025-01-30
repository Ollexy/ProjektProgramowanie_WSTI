#include "UserManager.h"
#include "User.h"

UserManager::UserManager() {
    users.push_back(new User("admin", "admin", true));  // Administrator
    users.push_back(new User("user", "user", false));   // Zwykły użytkownik
}

bool UserManager::authenticate(const std::string& login, const std::string& password) const {
    for (const auto& user : users) {
        if (user->getLogin() == login && user->getPassword() == password) {
            return true;
        }
    }
    return false;
}

User* UserManager::getUserByUsername(const std::string& username) {
    for (auto& user : users) {
        if (user->getLogin() == username) {
            return user;  // Zwróć wskaźnik na użytkownika
        }
    }
    return nullptr;  // Jeśli użytkownik o takim loginie nie istnieje
}

std::string UserManager::getRole(const std::string& login) const {
    for (const auto& user : users) {
        if (user->getLogin() == login) {
            return user->isAdminUser() ? "admin" : "user";  // Zwróć rolę (admin lub user)
        }
    }
    return "";  // Jeśli użytkownik nie istnieje
}
