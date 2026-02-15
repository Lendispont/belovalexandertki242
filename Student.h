#include "Person.h"
#include <string>
#include <memory>

class Group;

class Student : public Person {
private:
    std::string recordBookNumber;
    std::shared_ptr<Group> group;
    std::string specialization;

public:
    Student(int id, const std::string& firstName, const std::string& lastName,
            const std::string& patronymic, const std::string& recordBookNumber,
            const std::shared_ptr<Group>& group, const std::string& specialization);

    std::string getInfo() const override;
    std::string getType() const override;

    std::string getRecordBookNumber() const;
    std::shared_ptr<Group> getGroup() const;
    std::string getSpecialization() const;

    bool matchByRecordBook(const std::string& recordBook) const;
    bool matchByName(const std::string& searchName) const;
};
