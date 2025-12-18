#include <string>

class Person {
protected:
    std::string firstName;
    std::string lastName;
    std::string patronymic;
    
public:
    Person(const std::string& firstName, const std::string& lastName, 
           const std::string& patronymic = "");
    virtual ~Person() = default;
    
    virtual std::string getInfo() const;
    virtual std::string getType() const;
    
    std::string getFullName() const;
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getPatronymic() const;
}
