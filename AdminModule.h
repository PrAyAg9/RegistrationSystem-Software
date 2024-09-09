#ifndef ADMIN_MODULE_H
#define ADMIN_MODULE_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Enumerations for user roles
enum class UserRole {
    STUDENT,
    FACULTY,
    HOD,
    REGISTRAR,
    ACCOUNTS_OFFICER,
    DEAN,
    ADMIN
};

// Structure for User
struct User {
    int userID;
    std::string username;
    std::string password;
    UserRole role;

    User(int id, const std::string& uname, const std::string& pwd, UserRole r)
        : userID(id), username(uname), password(pwd), role(r) {}
};

class AdminModule {
private:
    std::vector<User> users;
    int userCounter = 1;

public:
    void addUser(const std::string& username, const std::string& password, UserRole role);
    void deleteUser(int userID);
    User* authenticateUser(const std::string& username, const std::string& password);
    void displayUsers() const;
    std::vector<User> getUsers() const;
};

#endif // ADMIN_MODULE_H
