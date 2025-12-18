#include <gtest/gtest.h>
#include <memory>
#include "Person.h"
#include "Student.h"
#include "Teacher.h"
#include "Department.h"
#include "Group.h"
#include "UniversitySystem.h"

// Тесты для класса Person
TEST(PersonTest, ConstructorAndGetters) {
    Person person("Иван", "Иванов", "Иванович");
    
    EXPECT_EQ(person.getFirstName(), "Иван");
    EXPECT_EQ(person.getLastName(), "Иванов");
    EXPECT_EQ(person.getPatronymic(), "Иванович");
    EXPECT_EQ(person.getFullName(), "Иванов Иван Иванович");
    EXPECT_EQ(person.getType(), "Person");
}

TEST(PersonTest, WithoutPatronymic) {
    Person person("Иван", "Иванов");
    
    EXPECT_EQ(person.getPatronymic(), "");
    EXPECT_EQ(person.getFullName(), "Иванов Иван");
}

TEST(StudentTest, ConstructorAndGetters) {
    Student student("Анна", "Смирнова", "Александровна", 
                   "2023001", "101-ИВТ", "Информатика");
    
    EXPECT_EQ(student.getFirstName(), "Анна");
    EXPECT_EQ(student.getRecordBookNumber(), "2023001");
    EXPECT_EQ(student.getGroupName(), "101-ИВТ");
    EXPECT_EQ(student.getSpecialization(), "Информатика");
    EXPECT_EQ(student.getType(), "Student");
}

TEST(StudentTest, GetInfo) {
    Student student("Анна", "Смирнова", "Александровна", 
                   "2023001", "101-ИВТ", "Информатика");
    
    std::string info = student.getInfo();
    EXPECT_NE(info.find("Смирнова Анна Александровна"), std::string::npos);
    EXPECT_NE(info.find("2023001"), std::string::npos);
    EXPECT_NE(info.find("101-ИВТ"), std::string::npos);
}

TEST(StudentTest, MatchByRecordBook) {
    Student student("Анна", "Смирнова", "Александровна", 
                   "2023001", "101-ИВТ", "Информатика");
    
    EXPECT_TRUE(student.matchByRecordBook("2023001"));
    EXPECT_FALSE(student.matchByRecordBook("2023002"));
}

TEST(TeacherTest, ConstructorAndGetters) {
    Teacher teacher("Иван", "Иванов", "Иванович", "Кафедра информатики");
    
    EXPECT_EQ(teacher.getFirstName(), "Иван");
    EXPECT_EQ(teacher.getDepartment(), "Кафедра информатики");
    EXPECT_EQ(teacher.getType(), "Teacher");
    EXPECT_TRUE(teacher.getCourses().empty());
}

TEST(TeacherTest, AddAndRemoveCourses) {
    Teacher teacher("Иван", "Иванов", "Иванович", "Кафедра информатики");
    
    teacher.addCourse("Программирование");
    teacher.addCourse("Алгоритмы");
    
    EXPECT_EQ(teacher.getCourses().size(), 2);
    EXPECT_TRUE(teacher.teachesCourse("Программирование"));
    EXPECT_TRUE(teacher.teachesCourse("Алгоритмы"));
    EXPECT_FALSE(teacher.teachesCourse("Математика"));
    
    teacher.removeCourse("Алгоритмы");
    EXPECT_EQ(teacher.getCourses().size(), 1);
    EXPECT_FALSE(teacher.teachesCourse("Алгоритмы"));
}

TEST(DepartmentTest, ConstructorAndGetters) {
    Department dept("Кафедра информатики");
    
    EXPECT_EQ(dept.getName(), "Кафедра информатики");
    EXPECT_TRUE(dept.getCourses().empty());
}

TEST(DepartmentTest, AddAndRemoveCourses) {
    Department dept("Кафедра информатики");
    
    dept.addCourse("Программирование");
    dept.addCourse("Алгоритмы");
    
    EXPECT_EQ(dept.getCourses().size(), 2);
    EXPECT_TRUE(dept.hasCourse("Программирование"));
    EXPECT_TRUE(dept.hasCourse("Алгоритмы"));
    
    dept.removeCourse("Алгоритмы");
    EXPECT_EQ(dept.getCourses().size(), 1);
    EXPECT_FALSE(dept.hasCourse("Алгоритмы"));
}

TEST(GroupTest, ConstructorAndGetters) {
    Group group("101-ИВТ", "Информатика");
    
    EXPECT_EQ(group.getName(), "101-ИВТ");
    EXPECT_EQ(group.getSpecialization(), "Информатика");
    EXPECT_TRUE(group.getStudents().empty());
    EXPECT_TRUE(group.getTeachers().empty());
}

TEST(UniversitySystemTest, AddAndFindStudents) {
    UniversitySystem university;
    
    auto student = std::make_shared<Student>("Анна", "Смирнова", "Александровна", 
                                            "2023001", "101-ИВТ", "Информатика");
    university.addStudent(student);
    
    auto found = university.findStudentByRecordBook("2023001");
    EXPECT_NE(found, nullptr);
    EXPECT_EQ(found->getRecordBookNumber(), "2023001");
    
    auto notFound = university.findStudentByRecordBook("9999999");
    EXPECT_EQ(notFound, nullptr);
}

TEST(UniversitySystemTest, GetDepartmentCourses) {
    UniversitySystem university;
    
    auto dept = std::make_shared<Department>("Кафедра информатики");
    dept->addCourse("Программирование");
    dept->addCourse("Алгоритмы");
    
    university.addDepartment(dept);
    
    auto courses = university.getDepartmentCourses("Кафедра информатики");
    EXPECT_EQ(courses.size(), 2);
    EXPECT_EQ(courses[0], "Программирование");
    EXPECT_EQ(courses[1], "Алгоритмы");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
