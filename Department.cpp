#include "Department.h"

Department::Department(const std::string& name) : name(name) {}

std::string Department::getName() const { return name; }

const std::vector<std::string>& Department::getCourses() const { return courses; }

void Department::addCourse(const std::string& course) {
    courses.push_back(course);
}

void Department::removeCourse(const std::string& course) {
    for (auto it = courses.begin(); it != courses.end(); ++it) {
        if (*it == course) {
            courses.erase(it);
            break;
        }
    }
}

bool Department::hasCourse(const std::string& course) const {
    for (const auto& c : courses) {
        if (c == course) return true;
    }
    return false;
}
