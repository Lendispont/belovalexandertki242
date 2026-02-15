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

    auto ivanov = std::make_shared<Teacher>(1, "Иван", "Иванов", "Иванович", csDept);
    auto petrova = std::make_shared<Teacher>(2, "Мария", "Петрова", "Сергеевна", mathDept);
    auto sidorov = std::make_shared<Teacher>(3, "Алексей", "Сидоров", "Петрович", physDept);

    university.addTeacher(ivanov);
    university.addTeacher(petrova);
    university.addTeacher(sidorov);

    auto group101 = std::make_shared<Group>("101-ИВТ", "Информатика и вычислительная техника", csDept);
    auto group102 = std::make_shared<Group>("102-ПМИ", "Прикладная математика и информатика", mathDept);

    university.addGroup(group101);
    university.addGroup(group102);

    group101->addTeacher(ivanov);
    group101->addTeacher(petrova);
    ivanov->addGroup(group101);
    petrova->addGroup(group101);

    group102->addTeacher(ivanov);
    group102->addTeacher(sidorov);
    ivanov->addGroup(group102);
    sidorov->addGroup(group102);

    csDept->addTeacher(ivanov);
    mathDept->addTeacher(petrova);
    physDept->addTeacher(sidorov);

    csDept->addGroup(group101);
    mathDept->addGroup(group102);

    auto student1 = std::make_shared<Student>(4, "Анна", "Смирнова", "Александровна",
                                               "2023001", group101, "Информатика и вычислительная техника");
    auto student2 = std::make_shared<Student>(5, "Дмитрий", "Кузнецов", "Викторович",
                                               "2023002", group101, "Информатика и вычислительная техника");
    auto student3 = std::make_shared<Student>(6, "Елена", "Васильева", "Игоревна",
                                               "2023003", group102, "Прикладная математика и информатика");
    auto student4 = std::make_shared<Student>(7, "Сергей", "Попов", "Андреевич",
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

    std::cout << "\n=== ВЫПОЛНЕНИЕ ЗАДАНИЙ ===\n";

    std::cout << "\n1. Поиск по зачетке '2023002':\n";
    auto found = university.findStudentByRecordBook("2023002");
    std::cout << (found ? found->getInfo() : "Не найден") << "\n";

    std::cout << "\n2. Поиск по фамилии 'Смирнова':\n";
    for (const auto& s : university.findStudentsByName("Смирнова"))
        std::cout << s->getInfo() << "\n";

    std::cout << "\n3. Дисциплины кафедры информатики:\n";
    for (const auto& c : university.getDepartmentCourses("Кафедра информатики"))
        std::cout << "- " << c << "\n";

    std::cout << "\n4. Преподаватели группы 101-ИВТ:\n";
    for (const auto& t : university.getGroupTeachers("101-ИВТ"))
        std::cout << "- " << t << "\n";

    std::cout << "\n5. Группы специальности 'Информатика и вычислительная техника':\n";
    for (const auto& g : university.getSpecializationGroups("Информатика и вычислительная техника"))
        std::cout << "- " << g << "\n";

    std::cout << "\n=== СТАТИСТИКА ===\n";
    std::cout << "Студентов: " << university.getAllStudents().size() << "\n";
    std::cout << "Преподавателей: " << university.getAllTeachers().size() << "\n";
    std::cout << "Кафедр: " << university.getAllDepartments().size() << "\n";
    std::cout << "Групп: " << university.getAllGroups().size() << "\n";
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
