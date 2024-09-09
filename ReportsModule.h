#ifndef REPORTS_MODULE_H
#define REPORTS_MODULE_H

#include <iostream>
#include <vector>
#include "AdminModule.h"
#include "TransactionsModule.h"

class ReportsModule {
public:
    void generateStudentReport(const std::vector<Registration>& registrations, const std::vector<User>& users);
};

#endif // REPORTS_MODULE_H
