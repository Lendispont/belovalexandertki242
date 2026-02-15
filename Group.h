class Student;
class Teacher;
class Department;

class Group {
private:
    std::string name;
    std::string specialization;
    std::shared_ptr<Department> department;
    std::vector<std::shared_ptr<Student>> students;
    std::vector<std::shared_ptr<Teacher>> teachers;

public:
    Group(const std::string& name, const std::string& specialization,
          const std::shared_ptr<Department>& department = nullptr);

    std::string getName() const;
    std::string getSpecialization() const;
    std::shared_ptr<Department> getDepartment() const;

    void addStudent(const std::shared_ptr<Student>& student);
    void addTeacher(const std::shared_ptr<Teacher>& teacher);

    const std::vector<std::shared_ptr<Student>>& getStudents() const;
    const std::vector<std::shared_ptr<Teacher>>& getTeachers() const;

    std::vector<std::string> getTeacherNames() const;
}
