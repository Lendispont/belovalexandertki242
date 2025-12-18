#include <string>
#include <vector>

class Department {
private:
    std::string name;
    std::vector<std::string> courses;
    
public:
    Department(const std::string& name);
    
    std::string getName() const;
    const std::vector<std::string>& getCourses() const;
    
    void addCourse(const std::string& course);
    void removeCourse(const std::string& course);
    bool hasCourse(const std::string& course) const;
}
