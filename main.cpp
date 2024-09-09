#include "AdminModule.h"
#include "MastersModule.h"
#include "TransactionsModule.h"
#include "ReportsModule.h"
#include "UtilitiesModule.h"

void displayMainMenu() {
    std::cout << "\n=== Online Student Course Registration System ===\n";
    std::cout << "1. Manage Users\n";
    std::cout << "2. Manage Courses\n";
    std::cout << "3. Register Courses\n";
    std::cout << "4. Generate Reports\n";
    std::cout << "5. Backup Data\n";
    std::cout << "6. Exit\n";
    std::cout << "Select an option: ";
}

void manageUsers(AdminModule& adminModule) {
    int choice;
    std::string username, password;
    int userID;
    UserRole role;

    while (true) {
        std::cout << "\n=== Manage Users ===\n";
        std::cout << "1. Add User\n";
        std::cout << "2. Delete User\n";
        std::cout << "3. Display Users\n";
        std::cout << "4. Back to Main Menu\n";
        std::cout << "Select an option: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter username: ";
                std::cin >> username;
                std::cout << "Enter password: ";
                std::cin >> password;
                std::cout << "Enter role (0-6): ";
                int roleInt;
                std::cin >> roleInt;
                role = static_cast<UserRole>(roleInt);
                adminModule.addUser(username, password, role);
                break;
            case 2:
                std::cout << "Enter user ID to delete: ";
                std::cin >> userID;
                adminModule.deleteUser(userID);
                break;
            case 3:
                adminModule.displayUsers();
                break;
            case 4:
                return;
            default:
                std::cout << "Invalid option! Try again.\n";
        }
    }
}

void manageCourses(MastersModule& mastersModule) {
    int choice;
    std::string courseName, courseCategory;
    int courseID, credits;

    while (true) {
        std::cout << "\n=== Manage Courses ===\n";
        std::cout << "1. Add Course\n";
        std::cout << "2. Delete Course\n";
        std::cout << "3. Display Courses\n";
        std::cout << "4. Back to Main Menu\n";
        std::cout << "Select an option: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter course name: ";
                std::cin >> courseName;
                std::cout << "Enter course category: ";
                std::cin >> courseCategory;
                std::cout << "Enter credits: ";
                std::cin >> credits;
                mastersModule.addCourse(courseName, courseCategory, credits);
                break;
            case 2:
                std::cout << "Enter course ID to delete: ";
                std::cin >> courseID;
                mastersModule.deleteCourse(courseID);
                break;
            case 3:
                mastersModule.displayCourses();
                break;
            case 4:
                return;
            default:
                std::cout << "Invalid option! Try again.\n";
        }
    }
}

void registerCourses(TransactionsModule& transactionsModule) {
    int studentID, registrationID;
    std::vector<int> courseIDs;
    int courseID, choice;

    while (true) {
        std::cout << "\n=== Register Courses ===\n";
        std::cout << "1. Register Student for Courses\n";
        std::cout << "2. Process Payment\n";
        std::cout << "3. Display Registrations\n";
        std::cout << "4. Back to Main Menu\n";
        std::cout << "Select an option: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter student ID: ";
                std::cin >> studentID;
                courseIDs.clear();
                std::cout << "Enter course IDs (enter -1 to stop): ";
                while (true) {
                    std::cin >> courseID;
                    if (courseID == -1) break;
                    courseIDs.push_back(courseID);
                }
                transactionsModule.registerCourses(studentID, courseIDs);
                break;
            case 2:
                std::cout << "Enter registration ID to process payment: ";
                std::cin >> registrationID;
                transactionsModule.processPayment(registrationID);
                break;
            case 3:
                transactionsModule.displayRegistrations();
                break;
            case 4:
                return;
            default:
                std::cout << "Invalid option! Try again.\n";
        }
    }
}

void generateReports(ReportsModule& reportsModule, TransactionsModule& transactionsModule, AdminModule& adminModule) {
    std::cout << "\n=== Generate Reports ===\n";
    reportsModule.generateStudentReport(transactionsModule.getRegistrations(), adminModule.getUsers());
}

void backupData(UtilitiesModule& utilitiesModule, AdminModule& adminModule, MastersModule& mastersModule, TransactionsModule& transactionsModule) {
    std::cout << "\n=== Backup Data ===\n";
    utilitiesModule.backupData(adminModule.getUsers(), mastersModule.getCourses(), transactionsModule.getRegistrations());
}

int main() {
    AdminModule adminModule;
    MastersModule mastersModule;
    TransactionsModule transactionsModule;
    ReportsModule reportsModule;
    UtilitiesModule utilitiesModule;

    int choice;
    while (true) {
        displayMainMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                manageUsers(adminModule);
                break;
            case 2:
                manageCourses(mastersModule);
                break;
            case 3:
                registerCourses(transactionsModule);
                break;
            case 4:
                generateReports(reportsModule, transactionsModule, adminModule);
                break;
            case 5:
                backupData(utilitiesModule, adminModule, mastersModule, transactionsModule);
                break;
            case 6:
                std::cout << "Exiting the system. Goodbye!\n";
                return 0;
            default:
                std::cout << "Invalid option! Try again.\n";
        }
    }
    return 0;
}
