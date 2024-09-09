#include "ReportsModule.h"

void ReportsModule::generateStudentReport(const std::vector<Registration>& registrations, const std::vector<User>& users) {
    std::cout << "Student Registration Report:\n";
    for (const auto& reg : registrations) {
        auto it = std::find_if(users.begin(), users.end(), [reg](const User& u) { return u.userID == reg.studentID; });
        if (it != users.end()) {
            std::cout << "Student ID: " << reg.studentID << ", Username: " << it->username << ", Courses Registered: " << reg.courseIDs.size() << "\n";
        }
    }
}
