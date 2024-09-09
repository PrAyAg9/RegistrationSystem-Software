#include "AdminModule.h"

void AdminModule::addUser(const std::string& username, const std::string& password, UserRole role) {
    users.emplace_back(userCounter++, username, password, role);
    std::cout << "User " << username << " added successfully.\n";
}

void AdminModule::deleteUser(int userID) {
    users.erase(std::remove_if(users.begin(), users.end(), [userID](const User& u) { return u.userID == userID; }), users.end());
    std::cout << "User with ID " << userID << " deleted successfully.\n";
}

User* AdminModule::authenticateUser(const std::string& username, const std::string& password) {
    for (auto& user : users) {
        if (user.username == username && user.password == password) {
            std::cout << "User authenticated successfully.\n";
            return &user;
        }
    }
    std::cout << "Authentication failed.\n";
    return nullptr;
}

void AdminModule::displayUsers() const {
    std::cout << "Current Users:\n";
    for (const auto& user : users) {
        std::cout << "ID: " << user.userID << ", Username: " << user.username << ", Role: " << static_cast<int>(user.role) << "\n";
    }
}

std::vector<User> AdminModule::getUsers() const {
    return users;
}
