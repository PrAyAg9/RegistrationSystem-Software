#include "UtilitiesModule.h"

void UtilitiesModule::backupData(const std::vector<User>& users, const std::vector<Course>& courses, const std::vector<Registration>& registrations) {
    std::ofstream backupFile("backup.txt");
    if (backupFile.is_open()) {
        backupFile << "Users:\n";
        for (const auto& user : users) {
            backupFile << user.userID << " " << user.username << " " << static_cast<int>(user.role) << "\n";
        }
        backupFile << "\nCourses:\n";
        for (const auto& course : courses) {
            backupFile << course.courseID << " " << course.courseName << " " << course.courseCategory << " " << course.credits << "\n";
        }
        backupFile << "\nRegistrations:\n";
        for (const auto& reg : registrations) {
            backupFile << reg.registrationID << " " << reg.studentID << " " << reg.paymentCompleted << "\n";
        }
        backupFile.close();
        std::cout << "Backup completed successfully.\n";
    } else {
        std::cout << "Failed to create backup file.\n";
    }
}
