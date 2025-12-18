#include <iostream>
#include <memory>
#include <vector>
#include "Person.h"
#include "Student.h"
#include "Teacher.h"
#include "Department.h"
#include "Group.h"
#include "UniversitySystem.h"

void demonstrateUniversitySystem() {
    UniversitySystem university;
    
    auto csDept = std::make_shared<Department>("Кафедра информатики");
    auto mathDept = std::make_shared<Department>("Кафедра математики");
    auto physDept = std::make_shared<Department>("Кафедра физики");
    
    csDept->addCourse("Программирование");
    csDept->addCourse("Алгоритмы");
    csDept->addCourse("Базы данных");
    
    mathDept->addCourse("Математический анализ");
    mathDept->addCourse("Линейная алгебра");
    mathDept->addCourse("Дискретная математика");
    
    physDept->addCourse("Общая физика");
    physDept->addCourse("Механика");
    physDept->addCourse("Электричество");
    
    university.addDepartment(csDept);
    university.addDepartment(mathDept);
    university.addDepartment(physDept);
    
    auto ivanov = std::make_shared<Teacher>("Иван", "Иванов", "Иванович", "Кафедра информатики");
    ivanov->addCourse("Программирование");
    ivanov->addCourse("Алгоритмы");
    
    auto petrova = std::make_shared<Teacher>("Мария", "Петрова", "Сергеевна", "Кафедра математики");
    petrova->addCourse("Математический анализ");
    petrova->addCourse("Линейная алгебра");
    
    auto sidorov = std::make_shared<Teacher>("Алексей", "Сидоров", "Петрович", "Кафедра физики");
    sidorov->addCourse("Общая физика");
    sidorov->addCourse("Механика");
    
    university.addTeacher(ivanov);
    university.addTeacher(petrova);
    university.addTeacher(sidorov);
    
    auto group101 = std::make_shared<Group>("101-ИВТ", "Информатика и вычислительная техника");
    auto group102 = std::make_shared<Group>("102-ПМИ", "Прикладная математика и информатика");
    
    university.addGroup(group101);
    university.addGroup(group102);
    
    group101->addTeacher(ivanov);
    group101->addTeacher(petrova);
    
    group102->addTeacher(ivanov);
    group102->addTeacher(sidorov);
    
    auto student1 = std::make_shared<Student>("Анна", "Смирнова", "Александровна", 
                                             "2023001", "101-ИВТ", "Информатика и вычислительная техника");
    auto student2 = std::make_shared<Student>("Дмитрий", "Кузнецов", "Викторович",
                                             "2023002", "101-ИВТ", "Информатика и вычислительная техника");
    auto student3 = std::make_shared<Student>("Елена", "Васильева", "Игоревна",
                                             "2023003", "102-ПМИ", "Прикладная математика и информатика");
    auto student4 = std::make_shared<Student>("Сергей", "Попов", "Андреевич",
                                             "2023004", "102-ПМИ", "Прикладная математика и информатика");
    
    university.addStudent(student1);
    university.addStudent(student2);
    university.addStudent(student3);
    university.addStudent(student4);
    
    group101->addStudent(student1);
    group101->addStudent(student2);
    group102->addStudent(student3);
    group102->addStudent(student4);
    
    std::vector<std::shared_ptr<Person>> people;
    
    people.push_back(student1);
    people.push_back(student2);
    people.push_back(student3);
    people.push_back(student4);
    people.push_back(ivanov);
    people.push_back(petrova);
    people.push_back(sidorov);
    
    std::cout << "=== ИТЕРАЦИЯ ПО КОЛЛЕКЦИИ ОБЪЕКТОВ БАЗОВОГО ТИПА ===" << std::endl;
    std::cout << "Всего объектов в коллекции: " << people.size() << std::endl << std::endl;
    
    for (const auto& person : people) {
        std::cout << "Тип: " << person->getType() << std::endl;
        std::cout << "Информация: " << person->getInfo() << std::endl;
        std::cout << "---" << std::endl;
    }
    
    std::cout << "\n=== ВЫПОЛНЕНИЕ ЗАДАНИЙ ===" << std::endl;
    
    std::cout << "\n1. Поиск студента по номеру зачетной книжки '2023002':" << std::endl;
    auto foundStudent = university.findStudentByRecordBook("2023002");
    if (foundStudent) {
        std::cout << "Найден: " << foundStudent->getInfo() << std::endl;
    } else {
        std::cout << "Студент не найден" << std::endl;
    }
    
    std::cout << "\n2. Поиск студентов по имени 'Смирнова':" << std::endl;
    auto foundStudents = university.findStudentsByName("Смирнова");
    if (!foundStudents.empty()) {
        for (const auto& s : foundStudents) {
            std::cout << "Найден: " << s->getInfo() << std::endl;
        }
    } else {
        std::cout << "Студенты не найдены" << std::endl;
    }
    
    std::cout << "\n3. Дисциплины кафедры 'Кафедра информатики':" << std::endl;
    auto csCourses = university.getDepartmentCourses("Кафедра информатики");
    for (const auto& course : csCourses) {
        std::cout << "- " << course << std::endl;
    }
    
    std::cout << "\n4. Преподаватели группы '101-ИВТ':" << std::endl;
    auto groupTeachers = university.getGroupTeachers("101-ИВТ");
    for (const auto& teacher : groupTeachers) {
        std::cout << "- " << teacher << std::endl;
    }
    
    std::cout << "\n5. Группы специальности 'Информатика и вычислительная техника':" << std::endl;
    auto specGroups = university.getSpecializationGroups("Информатика и вычислительная техника");
    for (const auto& group : specGroups) {
        std::cout << "- " << group << std::endl;
    }
    
    std::cout << "\n=== СТАТИСТИКА ===" << std::endl;
    std::cout << "Всего студентов: " << university.getAllStudents().size() << std::endl;
    std::cout << "Всего преподавателей: " << university.getAllTeachers().size() << std::endl;
    std::cout << "Всего кафедр: " << university.getAllDepartments().size() << std::endl;
    std::cout << "Всего групп: " << university.getAllGroups().size() << std::endl;
}

int main() {
    try {
        demonstrateUniversitySystem();
    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
