#ifndef UTILITIES_MODULE_H
#define UTILITIES_MODULE_H

#include <iostream>
#include <vector>
#include <fstream>
#include "AdminModule.h"
#include "MastersModule.h"
#include "TransactionsModule.h"

class UtilitiesModule {
public:
    void backupData(const std::vector<User>& users, const std::vector<Course>& courses, const std::vector<Registration>& registrations);
};

#endif // UTILITIES_MODULE_H
