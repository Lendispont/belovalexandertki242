#include "Student.h"
#include "Group.h"

Student::Student(int id, const std::string& firstName, const std::string& lastName,
                 const std::string& patronymic, const std::string& recordBookNumber,
                 const std::shared_ptr<Group>& group, const std::string& specialization)
    : Person(id, firstName, lastName, patronymic), 
      recordBookNumber(recordBookNumber),
      group(group),
      specialization(specialization) {}

std::string Student::getInfo() const {
    std::string info = getFullName() + " (ID: " + std::to_string(getId()) + ")";
    info += " | Зачетка: " + recordBookNumber;
    if (group) {
        info += " | Группа: " + group->getName();
    }
    info += " | Специальность: " + specialization;
    return info;
}

std::string Student::getType() const {
    return "Student";
}

std::string Student::getRecordBookNumber() const { return recordBookNumber; }
std::shared_ptr<Group> Student::getGroup() const { return group; }
std::string Student::getSpecialization() const { return specialization; }

bool Student::matchByRecordBook(const std::string& recordBook) const {
    return recordBookNumber == recordBook;
}

bool Student::matchByName(const std::string& searchName) const {
    std::string fullName = getFullName();
    return fullName.find(searchName) != std::string::npos;
}
