#ifndef MASTERS_MODULE_H
#define MASTERS_MODULE_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Structure for Course
struct Course {
    int courseID;
    std::string courseName;
    std::string courseCategory;
    int credits;

    Course(int id, const std::string& name, const std::string& category, int credit)
        : courseID(id), courseName(name), courseCategory(category), credits(credit) {}
};

class MastersModule {
private:
    std::vector<Course> courses;
    int courseCounter = 1;

public:
    void addCourse(const std::string& courseName, const std::string& courseCategory, int credits);
    void deleteCourse(int courseID);
    void displayCourses() const;
    Course* findCourse(int courseID);
    std::vector<Course> getCourses() const;
};

#endif // MASTERS_MODULE_H
