#include "Person.h"
#include <stdexcept>
#include <algorithm>

int Person::nextId = 1;
std::set<int> Person::existingIds;

bool Person::isIdUnique(int id) {
    return existingIds.find(id) == existingIds.end();
}

int Person::generateUniqueId() {
    while (!isIdUnique(nextId)) {
        ++nextId;
    }
    int newId = nextId;
    ++nextId;
    return newId;
}

Person::Person(const std::string& firstName, const std::string& lastName,
               const std::string& patronymic)
    : id(generateUniqueId()), firstName(firstName), lastName(lastName), patronymic(patronymic) {
    existingIds.insert(id);
}

Person::Person(int id, const std::string& firstName, const std::string& lastName,
               const std::string& patronymic)
    : id(id), firstName(firstName), lastName(lastName), patronymic(patronymic) {
    
    if (!isIdUnique(id)) {
        throw std::invalid_argument("Person with ID " + std::to_string(id) + " already exists!");
    }
    
    existingIds.insert(id);
    
    if (id >= nextId) {
        nextId = id + 1;
    }
}

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
