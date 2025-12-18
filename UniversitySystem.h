#include <vector>
#include <memory>
#include <string>

class Student;
class Teacher;
class Department;
class Group;

class UniversitySystem {
private:
    std::vector<std::shared_ptr<Student>> students;
    std::vector<std::shared_ptr<Teacher>> teachers;
    std::vector<std::shared_ptr<Department>> departments;
    std::vector<std::shared_ptr<Group>> groups;
    
public:
    UniversitySystem();
    
    // Добавление элементов
    void addStudent(const std::shared_ptr<Student>& student);
    void addTeacher(const std::shared_ptr<Teacher>& teacher);
    void addDepartment(const std::shared_ptr<Department>& department);
    void addGroup(const std::shared_ptr<Group>& group);
    
    // Поиск студентов
    std::shared_ptr<Student> findStudentByRecordBook(const std::string& recordBook) const;
    std::vector<std::shared_ptr<Student>> findStudentsByName(const std::string& name) const;
    
    // Получение списков
    std::vector<std::string> getDepartmentCourses(const std::string& departmentName) const;
    std::vector<std::string> getGroupTeachers(const std::string& groupName) const;
    std::vector<std::string> getSpecializationGroups(const std::string& specialization) const;
    
    // Получение всех объектов
    const std::vector<std::shared_ptr<Student>>& getAllStudents() const;
    const std::vector<std::shared_ptr<Teacher>>& getAllTeachers() const;
    const std::vector<std::shared_ptr<Department>>& getAllDepartments() const;
    const std::vector<std::shared_ptr<Group>>& getAllGroups() const;
}
