#include "Person.h"
#include <string>
#include <vector>

class Teacher : public Person {
private:
    std::string department;
    std::vector<std::string> courses;
    
public:
    Teacher(const std::string& firstName, const std::string& lastName,
            const std::string& patronymic, const std::string& department);
    
    std::string getInfo() const override;
    std::string getType() const override;
    
    std::string getDepartment() const;
    const std::vector<std::string>& getCourses() const;
    
    void addCourse(const std::string& course);
    void removeCourse(const std::string& course);
    bool teachesCourse(const std::string& course) const;
}
