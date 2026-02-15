#include "Person.h"
#include <string>
#include <vector>
#include <memory>

class Department;
class Group;

class Teacher : public Person {
private:
    std::shared_ptr<Department> department;
    std::vector<std::shared_ptr<Group>> groups;

public:
    Teacher(int id, const std::string& firstName, const std::string& lastName,
            const std::string& patronymic, const std::shared_ptr<Department>& department);

    std::string getInfo() const override;
    std::string getType() const override;

    std::shared_ptr<Department> getDepartment() const;
    const std::vector<std::shared_ptr<Group>>& getGroups() const;

    void addGroup(const std::shared_ptr<Group>& group);
    void removeGroup(const std::shared_ptr<Group>& group);
    bool teachesInGroup(const std::shared_ptr<Group>& group) const;
};
