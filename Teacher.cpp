#include "Teacher.h"
#include "Department.h"
#include "Group.h"

Teacher::Teacher(const std::string& firstName, const std::string& lastName,
                 const std::string& patronymic, const std::shared_ptr<Department>& department)
    : Person(firstName, lastName, patronymic), department(department) {}

Teacher::Teacher(int id, const std::string& firstName, const std::string& lastName,
                 const std::string& patronymic, const std::shared_ptr<Department>& department)
    : Person(id, firstName, lastName, patronymic), department(department) {}

std::string Teacher::getInfo() const {
    std::string info = getFullName() + " (ID: " + std::to_string(getId()) + ")";
    if (department) {
        info += " | Кафедра: " + department->getName();
    }
    if (!groups.empty()) {
        info += " | Группы: ";
        for (size_t i = 0; i < groups.size(); ++i) {
            info += groups[i]->getName();
            if (i < groups.size() - 1) info += ", ";
        }
    }
    return info;
}

std::string Teacher::getType() const {
    return "Teacher";
}

std::shared_ptr<Department> Teacher::getDepartment() const { return department; }

const std::vector<std::shared_ptr<Group>>& Teacher::getGroups() const { return groups; }

void Teacher::addGroup(const std::shared_ptr<Group>& group) {
    groups.push_back(group);
}

void Teacher::removeGroup(const std::shared_ptr<Group>& group) {
    for (auto it = groups.begin(); it != groups.end(); ++it) {
        if (*it == group) {
            groups.erase(it);
            break;
        }
    }
}

bool Teacher::teachesInGroup(const std::shared_ptr<Group>& group) const {
    for (const auto& g : groups) {
        if (g == group) return true;
    }
    return false;
}
