#include "TransactionsModule.h"

void TransactionsModule::registerCourses(int studentID, const std::vector<int>& courseIDs) {
    registrations.emplace_back(registrationCounter++, studentID, courseIDs);
    std::cout << "Courses registered successfully for student ID " << studentID << ".\n";
}

void TransactionsModule::processPayment(int registrationID) {
    for (auto& reg : registrations) {
        if (reg.registrationID == registrationID) {
            reg.paymentCompleted = true;
            std::cout << "Payment processed for registration ID " << registrationID << ".\n";
            return;
        }
    }
    std::cout << "Registration ID not found.\n";
}

void TransactionsModule::displayRegistrations() const {
    std::cout << "Current Registrations:\n";
    for (const auto& reg : registrations) {
        std::cout << "Registration ID: " << reg.registrationID << ", Student ID: " << reg.studentID << ", Payment Completed: " << (reg.paymentCompleted ? "Yes" : "No") << "\n";
    }
}

std::vector<Registration> TransactionsModule::getRegistrations() const {
    return registrations;
}
