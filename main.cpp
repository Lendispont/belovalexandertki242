#include <iostream>
#include <memory>
#include "Task1Exercise.h"
#include "Task2Exercise.h"
#include "Task3Exercise.h"
#include "RandomGenerator.h"
#include "IStreamGenerator.h"
#include "ConstantGenerator.h"

using namespace miit::algebra;

void demonstrate_task1()
{
    std::cout << "=== Задание 1 ===" << std::endl;
    
    {
        auto random_gen = std::make_unique<RandomGenerator>(-10, 10);
        Task1Exercise task1(8, std::move(random_gen));
        
        std::cout << "Случайное заполнение:" << std::endl;
        task1.execute();
        std::cout << "Результат: " << task1.get_matrix().to_string() << std::endl;
    }
    
    {
        std::cout << "\nВведите 5 элементов массива:" << std::endl;
        auto stream_gen = std::make_unique<IStreamGenerator>();
        Task1Exercise task1(5, std::move(stream_gen));
        
        task1.execute();
        std::cout << "Результат: " << task1.get_matrix().to_string() << std::endl;
    }
    
    {
        auto const_gen = std::make_unique<ConstantGenerator>(-5);
        Task1Exercise task1(6, std::move(const_gen));
        
        std::cout << "\nКонстантное заполнение (-5):" << std::endl;
        task1.execute();
        std::cout << "Результат: " << task1.get_matrix().to_string() << std::endl;
    }
}

void demonstrate_task2()
{
    std::cout << "\n=== Задание 2 ===" << std::endl;
    
    auto random_gen = std::make_unique<RandomGenerator>(-10, 10);
    Task2Exercise task2(6, std::move(random_gen));
    
    task2.execute();
    std::cout << "Результат (вставка K=5 перед элементами с цифрой 1): " 
              << task2.get_matrix().to_string() << std::endl;
}

void demonstrate_task3()
{
    std::cout << "\n=== Задание 3 ===" << std::endl;
    
    auto random_gen = std::make_unique<RandomGenerator>(1, 10);
    Task3Exercise task3(5, std::move(random_gen));
    
    task3.execute();
    std::cout << "Результат (преобразование массива D в A): " 
              << task3.get_matrix().to_string() << std::endl;
}

int main()
{
    try
    {
        demonstrate_task1();
        demonstrate_task2();
        demonstrate_task3();
    }
    catch (const std::exception& e)
    {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
