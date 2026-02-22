#include <iostream>
#include <memory>
#include "Task1Exercise.h"
#include "Task2Exercise.h"
#include "Task3Exercise.h"
#include "RandomGenerator.h"
#include "IStreamGenerator.h"
#include "ConstantGenerator.h"

using namespace miit::algebra;

int main()
{
    try
    {
        std::cout << "Введите размер массива: ";
        size_t size;
        std::cin >> size;

        std::cout << "Выберите способ заполнения:\n";
        std::cout << "1 - случайными числами в [-10,10]\n";
        std::cout << "2 - ввод с клавиатуры\n";
        std::cout << "3 - константой (значение 5)\n";
        std::cout << "Ваш выбор: ";
        int choice;
        std::cin >> choice;

        std::cout << "\n=== Задание 1 ===" << std::endl;
        {
            std::unique_ptr<Generator> gen;
            if (choice == 1) gen = std::make_unique<RandomGenerator>(-10, 10);
            else if (choice == 2) gen = std::make_unique<IStreamGenerator>();
            else gen = std::make_unique<ConstantGenerator>(5);

            Task1Exercise task1(size, std::move(gen));
            task1.execute();
            std::cout << "Результат: " << task1.get_matrix().to_string() << std::endl;
        }

        std::cout << "\n=== Задание 2 ===" << std::endl;
        {
            std::unique_ptr<Generator> gen;
            if (choice == 1) gen = std::make_unique<RandomGenerator>(-10, 10);
            else if (choice == 2) gen = std::make_unique<IStreamGenerator>();
            else gen = std::make_unique<ConstantGenerator>(5);

            Task2Exercise task2(size, std::move(gen));
            task2.execute();
            std::cout << "Результат: " << task2.get_matrix().to_string() << std::endl;
        }

        std::cout << "\n=== Задание 3 ===" << std::endl;
        {
            std::unique_ptr<Generator> gen;
            if (choice == 1) gen = std::make_unique<RandomGenerator>(-10, 10);
            else if (choice == 2) gen = std::make_unique<IStreamGenerator>();
            else gen = std::make_unique<ConstantGenerator>(5);

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
