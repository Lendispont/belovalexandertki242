#include "Student.h"

Student::Student(const std::string& firstName, const std::string& lastName,
                 const std::string& patronymic, const std::string& recordBookNumber,
                 const std::string& groupName, const std::string& specialization)
    : Person(firstName, lastName, patronymic), 
      recordBookNumber(recordBookNumber),
      groupName(groupName),
      specialization(specialization) {}

std::string Student::getInfo() const {
    return getFullName() + " | Зачетка: " + recordBookNumber + 
           " | Группа: " + groupName + " | Специальность: " + specialization;
}

std::string Student::getType() const {
    return "Student";
}

std::string Student::getRecordBookNumber() const { return recordBookNumber; }
std::string Student::getGroupName() const { return groupName; }
std::string Student::getSpecialization() const { return specialization; }

bool Student::matchByRecordBook(const std::string& recordBook) const {
    return recordBookNumber == recordBook;
}

bool Student::matchByName(const std::string& searchName) const {
    std::string fullNameLower = getFullName();
    std::string searchLower = searchName;
    
    return fullNameLower.find(searchName) != std::string::npos;
}
