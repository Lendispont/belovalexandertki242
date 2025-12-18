#include "Teacher.h"

Teacher::Teacher(const std::string& firstName, const std::string& lastName,
                 const std::string& patronymic, const std::string& department)
    : Person(firstName, lastName, patronymic), department(department) {}

std::string Teacher::getInfo() const {
    std::string info = getFullName() + " | Кафедра: " + department;
    if (!courses.empty()) {
        info += " | Дисциплины: ";
        for (size_t i = 0; i < courses.size(); ++i) {
            info += courses[i];
            if (i < courses.size() - 1) info += ", ";
        }
    }
    return info;
}

std::string Teacher::getType() const {
    return "Teacher";
}

std::string Teacher::getDepartment() const { return department; }

const std::vector<std::string>& Teacher::getCourses() const { return courses; }

void Teacher::addCourse(const std::string& course) {
    courses.push_back(course);
}

void Teacher::removeCourse(const std::string& course) {
    for (auto it = courses.begin(); it != courses.end(); ++it) {
        if (*it == course) {
            courses.erase(it);
            break;
        }
    }
}

bool Teacher::teachesCourse(const std::string& course) const {
    for (const auto& c : courses) {
        if (c == course) return true;
    }
    return false;
}
