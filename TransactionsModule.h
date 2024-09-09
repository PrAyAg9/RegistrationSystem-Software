#ifndef TRANSACTIONS_MODULE_H
#define TRANSACTIONS_MODULE_H

#include <iostream>
#include <vector>
#include <string>

// Structure for Student Registration
struct Registration {
    int registrationID;
    int studentID;
    std::vector<int> courseIDs;
    bool paymentCompleted;

    Registration(int regID, int stuID, const std::vector<int>& courses)
        : registrationID(regID), studentID(stuID), courseIDs(courses), paymentCompleted(false) {}
};

class TransactionsModule {
private:
    std::vector<Registration> registrations;
    int registrationCounter = 1;

public:
    void registerCourses(int studentID, const std::vector<int>& courseIDs);
    void processPayment(int registrationID);
    void displayRegistrations() const;
    std::vector<Registration> getRegistrations() const;
};

#endif // TRANSACTIONS_MODULE_H
