#include <iostream>
#include <memory>
#include "Task1Exercise.h"
#include "Task2Exercise.h"
#include "Task3Exercise.h"
#include "RandomGenerator.h"
#include "IStreamGenerator.h"
#include "ConstantGenerator.h"

using namespace miit::algebra;

const int RANDOM_CHOICE = 1;
const int STREAM_CHOICE = 2;
const int CONSTANT_CHOICE = 3;

const int RANDOM_MIN = -10;
const int RANDOM_MAX = 10;
const int CONSTANT_VALUE = 5;

std::unique_ptr<Generator> create_generator(int choice)
{
    switch (choice)
    {
        case RANDOM_CHOICE:
            return std::make_unique<RandomGenerator>(RANDOM_MIN, RANDOM_MAX);
        
        case STREAM_CHOICE:
            return std::make_unique<IStreamGenerator>();
        
        case CONSTANT_CHOICE:
            return std::make_unique<ConstantGenerator>(CONSTANT_VALUE);
        
        default:
            std::cout << "Неверный выбор. Используется случайное заполнение по умолчанию." << std::endl;
            return std::make_unique<RandomGenerator>(RANDOM_MIN, RANDOM_MAX);
    }
}

int main()
{
    try
    {
        std::cout << "Введите размер массива: ";
        size_t size;
        std::cin >> size;

        std::cout << "Выберите способ заполнения:\n";
        std::cout << RANDOM_CHOICE << " – случайными числами в [" 
                  << RANDOM_MIN << ", " << RANDOM_MAX << "]\n";
        std::cout << STREAM_CHOICE << " – ввод с клавиатуры\n";
        std::cout << CONSTANT_CHOICE << " – константой (значение " 
                  << CONSTANT_VALUE << ")\n";
        std::cout << "Ваш выбор: ";
        
        int choice;
        std::cin >> choice;

        std::cout << "\n=== Задание 1 (замена второго элемента на максимальный отрицательный) ===" << std::endl;
        {
            auto gen = create_generator(choice);
            Task1Exercise task1(size, std::move(gen));
            task1.execute();
            std::cout << "Результат: " << task1.get_matrix().to_string() << std::endl;
        }

        std::cout << "\n=== Задание 2 (вставка K перед элементами с цифрой 1) ===" << std::endl;
        {
            auto gen = create_generator(choice);
            Task2Exercise task2(size, std::move(gen));
            task2.execute();
            std::cout << "Результат: " << task2.get_matrix().to_string() << std::endl;
        }

        std::cout << "\n=== Задание 3 (формирование массива A по правилам) ===" << std::endl;
        {
            auto gen = create_generator(choice);
            Task3Exercise task3(size, std::move(gen));
            task3.execute();
            std::cout << "Результат: " << task3.get_matrix().to_string() << std::endl;
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
