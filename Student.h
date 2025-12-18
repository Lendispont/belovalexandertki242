#include "Person.h"
#include <string>

class Student : public Person {
private:
    std::string recordBookNumber;
    std::string groupName;
    std::string specialization;
    
public:
    Student(const std::string& firstName, const std::string& lastName,
            const std::string& patronymic, const std::string& recordBookNumber,
            const std::string& groupName, const std::string& specialization);
    
    std::string getInfo() const override;
    std::string getType() const override;
    
    std::string getRecordBookNumber() const;
    std::string getGroupName() const;
    std::string getSpecialization() const;
    
    bool matchByRecordBook(const std::string& recordBook) const;
    bool matchByName(const std::string& searchName) const;
}
