#include <iostream>
#include <memory>
#include "Matrix.h"
#include "ProblemSolution.h"
#include "RandomGenerator.h"
#include "IStreamGenerator.h"

using namespace miit::algebra;

void demonstrate_matrix_operations()
{
    std::cout << "=== Демонстрация работы с Matrix ===" << std::endl;
    
    Matrix<int> matrix(5);
    auto random_gen = std::make_unique<RandomGenerator>(-10, 10);
    
    for (size_t i = 0; i < matrix.get_size(); ++i)
    {
        matrix[i] = random_gen->generate();
    }
    
    std::cout << "Исходный массив: " << matrix.to_string() << std::endl;
    
    auto shifted_left = matrix << 2;
    auto shifted_right = matrix >> 1;
    
    std::cout << "Сдвиг влево на 2: " << shifted_left.to_string() << std::endl;
    std::cout << "Сдвиг вправо на 1: " << shifted_right.to_string() << std::endl;
    std::cout << "Элемент с индексом 2: " << matrix[2] << std::endl;
}

void demonstrate_exercise()
{
    std::cout << "\n=== Демонстрация задания варианта 1 ===" << std::endl;
    
    auto random_gen = std::make_unique<RandomGenerator>(-10, 10);
    Variant1Exercise exercise(8, std::move(random_gen));
    exercise.fill_matrix();
    
    Matrix<int> original = exercise.get_matrix();
    std::cout << "Исходный массив D: " << original.to_string() << std::endl;
    
    auto task1_result = exercise.Task1();
    std::cout << "Задание 1 (замена 2-го элемента): " << task1_result.to_string() << std::endl;
    
    auto task2_result = exercise.Task2();
    std::cout << "Задание 2 (вставка K перед элементами с цифрой 1): " << task2_result.to_string() << std::endl;
    
    auto task3_result = exercise.Task3(original);
    std::cout << "Задание 3 (массив A по формулам): " << task3_result.to_string() << std::endl;
}

void demonstrate_user_input()
{
    std::cout << "\n=== Демонстрация ввода с клавиатуры ===" << std::endl;
    
    std::cout << "Введите размер массива: ";
    size_t size;
    std::cin >> size;
    
    std::cout << "Введите " << size << " элементов массива:" << std::endl;
    auto stream_gen = std::make_unique<IStreamGenerator>();
    Variant1Exercise exercise(size, std::move(stream_gen));
    exercise.fill_matrix();
    
    Matrix<int> original = exercise.get_matrix();
    std::cout << "Введенный массив D: " << original.to_string() << std::endl;
    
    auto task1_result = exercise.Task1();
    auto task2_result = exercise.Task2();
    auto task3_result = exercise.Task3(original);
    
    std::cout << "Результат задания 1: " << task1_result.to_string() << std::endl;
    std::cout << "Результат задания 2: " << task2_result.to_string() << std::endl;
    std::cout << "Результат задания 3: " << task3_result.to_string() << std::endl;
}

int main()
{
    try
    {
        demonstrate_matrix_operations();
        demonstrate_exercise();
        demonstrate_user_input();
    }
    catch (const std::exception& e)
    {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
