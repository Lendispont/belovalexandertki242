#include <string>
#include <set>

class Person {
protected:
    static int nextId;
    static std::set<int> existingIds; 
    
    int id;
    std::string firstName;
    std::string lastName;
    std::string patronymic;
    
    static bool isIdUnique(int id);
    static int generateUniqueId();

public:
    Person(const std::string& firstName, const std::string& lastName,
           const std::string& patronymic = "");
    
    Person(int id, const std::string& firstName, const std::string& lastName,
           const std::string& patronymic = "");
    
    virtual ~Person() = default;

    virtual std::string getInfo() const;
    virtual std::string getType() const;

    int getId() const;
    std::string getFullName() const;
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getPatronymic() const;
}
