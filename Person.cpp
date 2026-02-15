#include "Person.h"

Person::Person(int id, const std::string& firstName, const std::string& lastName,
               const std::string& patronymic)
    : id(id), firstName(firstName), lastName(lastName), patronymic(patronymic) {}

std::string Person::getInfo() const {
    return getFullName() + " (ID: " + std::to_string(id) + ")";
}

std::string Person::getType() const {
    return "Person";
}

int Person::getId() const { return id; }

std::string Person::getFullName() const {
    if (patronymic.empty())
        return lastName + " " + firstName;
    return lastName + " " + firstName + " " + patronymic;
}

std::string Person::getFirstName() const { return firstName; }
std::string Person::getLastName() const { return lastName; }
std::string Person::getPatronymic() const { return patronymic; }
