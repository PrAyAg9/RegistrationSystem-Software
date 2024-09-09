#include "MastersModule.h"

void MastersModule::addCourse(const std::string& courseName, const std::string& courseCategory, int credits) {
    courses.emplace_back(courseCounter++, courseName, courseCategory, credits);
    std::cout << "Course " << courseName << " added successfully.\n";
}

void MastersModule::deleteCourse(int courseID) {
    courses.erase(std::remove_if(courses.begin(), courses.end(), [courseID](const Course& c) { return c.courseID == courseID; }), courses.end());
    std::cout << "Course with ID " << courseID << " deleted successfully.\n";
}

void MastersModule::displayCourses() const {
    std::cout << "Current Courses:\n";
    for (const auto& course : courses) {
        std::cout << "ID: " << course.courseID << ", Name: " << course.courseName << ", Category: " << course.courseCategory << ", Credits: " << course.credits << "\n";
    }
}

Course* MastersModule::findCourse(int courseID) {
    for (auto& course : courses) {
        if (course.courseID == courseID) {
            return &course;
        }
    }
    return nullptr;
}

std::vector<Course> MastersModule::getCourses() const {
    return courses;
}
