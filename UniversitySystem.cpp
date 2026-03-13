#include "UniversitySystem.h"
#include "Student.h"
#include "Teacher.h"
#include "Department.h"
#include "Group.h"

UniversitySystem::UniversitySystem() {}

void UniversitySystem::addStudent(const std::shared_ptr<Student>& student) {
    students.push_back(student);
}

void UniversitySystem::addTeacher(const std::shared_ptr<Teacher>& teacher) {
    teachers.push_back(teacher);
}

void UniversitySystem::addDepartment(const std::shared_ptr<Department>& department) {
    departments.push_back(department);
}

void UniversitySystem::addGroup(const std::shared_ptr<Group>& group) {
    groups.push_back(group);
}

std::shared_ptr<Student> UniversitySystem::findStudentByRecordBook(const std::string& recordBook) const {
    for (const auto& student : students) {
        if (student->matchByRecordBook(recordBook)) {
            return student;
        }
    }
    return nullptr;
}

std::vector<std::shared_ptr<Student>> UniversitySystem::findStudentsByName(const std::string& name) const {
    std::vector<std::shared_ptr<Student>> result;
    for (const auto& student : students) {
        if (student->matchByName(name)) {
            result.push_back(student);
        }
    }
    return result;
}

std::vector<std::string> UniversitySystem::getDepartmentCourses(const std::string& departmentName) const {
    for (const auto& dept : departments) {
        if (dept->getName() == departmentName) {
            return dept->getCourses();
        }
    }
    return {};
}

std::vector<std::string> UniversitySystem::getGroupTeachers(const std::string& groupName) const {
    for (const auto& group : groups) {
        if (group->getName() == groupName) {
            return group->getTeacherNames();
        }
    }
    return {};
}

std::vector<std::string> UniversitySystem::getSpecializationGroups(const std::string& specialization) const {
    std::vector<std::string> result;
    for (const auto& group : groups) {
        if (group->getSpecialization() == specialization) {
            result.push_back(group->getName());
        }
    }
    return result;
}

const std::vector<std::shared_ptr<Student>>& UniversitySystem::getAllStudents() const { return students; }
const std::vector<std::shared_ptr<Teacher>>& UniversitySystem::getAllTeachers() const { return teachers; }
const std::vector<std::shared_ptr<Department>>& UniversitySystem::getAllDepartments() const { return departments; }
const std::vector<std::shared_ptr<Group>>& UniversitySystem::getAllGroups() const { return groups; }
