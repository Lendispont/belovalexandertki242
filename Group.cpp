#include "Group.h"
#include "Student.h"
#include "Teacher.h"

Group::Group(const std::string& name, const std::string& specialization)
    : name(name), specialization(specialization) {}

std::string Group::getName() const { return name; }
std::string Group::getSpecialization() const { return specialization; }

void Group::addStudent(const std::shared_ptr<Student>& student) {
    students.push_back(student);
}

void Group::addTeacher(const std::shared_ptr<Teacher>& teacher) {
    teachers.push_back(teacher);
}

const std::vector<std::shared_ptr<Student>>& Group::getStudents() const {
    return students;
}

const std::vector<std::shared_ptr<Teacher>>& Group::getTeachers() const {
    return teachers;
}

std::vector<std::string> Group::getTeacherNames() const {
    std::vector<std::string> names;
    for (const auto& teacher : teachers) {
        names.push_back(teacher->getFullName());
    }
    return names;
}
