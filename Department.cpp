#include "Department.h"
#include "Teacher.h"
#include "Group.h"

Department::Department(const std::string& name) : name(name) {}

std::string Department::getName() const { return name; }

const std::vector<std::string>& Department::getCourses() const { return courses; }
const std::vector<std::shared_ptr<Teacher>>& Department::getTeachers() const { return teachers; }
const std::vector<std::shared_ptr<Group>>& Department::getGroups() const { return groups; }

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

void Department::addTeacher(const std::shared_ptr<Teacher>& teacher) {
    teachers.push_back(teacher);
}

void Department::addGroup(const std::shared_ptr<Group>& group) {
    groups.push_back(group);
}

bool Department::hasTeacher(const std::shared_ptr<Teacher>& teacher) const {
    for (const auto& t : teachers) {
        if (t == teacher) return true;
    }
    return false;
}

bool Department::hasGroup(const std::shared_ptr<Group>& group) const {
    for (const auto& g : groups) {
        if (g == group) return true;
    }
    return false;
}
