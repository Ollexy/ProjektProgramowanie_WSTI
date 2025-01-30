#ifndef USER_H
#define USER_H

#include <string>

class User {
public:
    User(const std::string& login, const std::string& password, bool isAdmin)
            : login(login), password(password), isAdmin(isAdmin) {}

    const std::string& getLogin() const { return login; }
    const std::string& getPassword() const { return password; }
    bool isAdminUser() const { return isAdmin; }

private:
    std::string login;
    std::string password;
    bool isAdmin;
};

#endif
