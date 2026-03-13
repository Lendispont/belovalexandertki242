#include <string>
#include <vector>
#include <memory>

class Teacher;
class Group;

class Department {
private:
    std::string name;
    std::vector<std::string> courses;
    std::vector<std::shared_ptr<Teacher>> teachers;
    std::vector<std::shared_ptr<Group>> groups;

public:
    Department(const std::string& name);

    std::string getName() const;
    const std::vector<std::string>& getCourses() const;
    const std::vector<std::shared_ptr<Teacher>>& getTeachers() const;
    const std::vector<std::shared_ptr<Group>>& getGroups() const;

    void addCourse(const std::string& course);
    void removeCourse(const std::string& course);
    bool hasCourse(const std::string& course) const;

    void addTeacher(const std::shared_ptr<Teacher>& teacher);
    void addGroup(const std::shared_ptr<Group>& group);

    bool hasTeacher(const std::shared_ptr<Teacher>& teacher) const;
    bool hasGroup(const std::shared_ptr<Group>& group) const;
}
