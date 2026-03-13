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

    // Преподаватели (ID генерируются автоматически)
    auto ivanov = std::make_shared<Teacher>("Иван", "Иванов", "Иванович", csDept);
    auto petrova = std::make_shared<Teacher>("Мария", "Петрова", "Сергеевна", mathDept);
    auto sidorov = std::make_shared<Teacher>("Алексей", "Сидоров", "Петрович", physDept);

    university.addTeacher(ivanov);
    university.addTeacher(petrova);
    university.addTeacher(sidorov);

    // Группы
    auto group101 = std::make_shared<Group>("101-ИВТ", "Информатика и вычислительная техника", csDept);
    auto group102 = std::make_shared<Group>("102-ПМИ", "Прикладная математика и информатика", mathDept);

    university.addGroup(group101);
    university.addGroup(group102);

    // Связи преподавателей с группами
    group101->addTeacher(ivanov);
    group101->addTeacher(petrova);
    ivanov->addGroup(group101);
    petrova->addGroup(group101);

    group102->addTeacher(ivanov);
    group102->addTeacher(sidorov);
    ivanov->addGroup(group102);
    sidorov->addGroup(group102);

    // Связи с кафедрами
    csDept->addTeacher(ivanov);
    mathDept->addTeacher(petrova);
    physDept->addTeacher(sidorov);

    csDept->addGroup(group101);
    mathDept->addGroup(group102);

    // Студенты (ID генерируются автоматически)
    auto student1 = std::make_shared<Student>("Анна", "Смирнова", "Александровна",
                                               "2023001", group101, "Информатика и вычислительная техника");
    auto student2 = std::make_shared<Student>("Дмитрий", "Кузнецов", "Викторович",
                                               "2023002", group101, "Информатика и вычислительная техника");
    auto student3 = std::make_shared<Student>("Елена", "Васильева", "Игоревна",
                                               "2023003", group102, "Прикладная математика и информатика");
    auto student4 = std::make_shared<Student>("Сергей", "Попов", "Андреевич",
                                               "2023004", group102, "Прикладная математика и информатика");

    university.addStudent(student1);
    university.addStudent(student2);
    university.addStudent(student3);
    university.addStudent(student4);

    group101->addStudent(student1);
    group101->addStudent(student2);
    group102->addStudent(student3);
    group102->addStudent(student4);

    std::vector<std::shared_ptr<Person>> people = { student1, student2, student3, student4,
                                                     ivanov, petrova, sidorov };

    std::cout << "=== ИТЕРАЦИЯ ПО КОЛЛЕКЦИИ БАЗОВОГО ТИПА ===\n";
    std::cout << "Всего объектов: " << people.size() << "\n\n";
    for (const auto& p : people) {
        std::cout << "Тип: " << p->getType() << "\nИнформация: " << p->getInfo() << "\n---\n";
    }

    std::cout << "\n=== ПРОВЕРКА УНИКАЛЬНОСТИ ID ===\n";
    std::cout << "ID Иванова: " << ivanov->getId() << std::endl;
    std::cout << "ID Петровой: " << petrova->getId() << std::endl;
    std::cout << "ID Сидорова: " << sidorov->getId() << std::endl;
    std::cout << "ID студента 1: " << student1->getId() << std::endl;
    std::cout << "ID студента 2: " << student2->getId() << std::endl;

    try {
        std::cout << "\nПытаемся создать человека с ID 1...\n";
        auto duplicate = std::make_shared<Person>(1, "Тест", "Тестов", "Тестович");
        std::cout << "Успех: " << duplicate->getInfo() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Ошибка: " << e.what() << std::endl;
    }
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
