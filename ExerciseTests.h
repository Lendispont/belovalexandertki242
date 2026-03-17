#pragma once
#include <gtest/gtest.h>
#include <sstream>
#include "Task1Exercise.h"
#include "Task2Exercise.h"
#include "Task3Exercise.h"
#include "IStreamGenerator.h"
#include "ConstantGenerator.h"

using namespace miit::algebra;

TEST(Task1ExerciseTest, Execute)
{
    std::stringstream test_input;
    test_input << "1 -5 3 -2 10 -8 7 -1";
    auto stream_gen = std::make_unique<IStreamGenerator>(test_input);
    Task1Exercise exercise(8, std::move(stream_gen));
    
    exercise.execute();
    auto result = exercise.get_matrix();
    
    // В тестовом массиве [-5, -2, -8, -1] максимальный отрицательный -1
    // Второй элемент (индекс 1) должен быть заменен на -1
    EXPECT_EQ(result[1], -1);
}

TEST(Task1ExerciseTest, NoNegativeNumbers)
{
    std::stringstream test_input;
    test_input << "1 5 3 2 10 8 7 1";
    auto stream_gen = std::make_unique<IStreamGenerator>(test_input);
    Task1Exercise exercise(8, std::move(stream_gen));
    
    exercise.execute();
    auto result = exercise.get_matrix();
    
    // Отрицательных нет, второй элемент должен остаться неизменным (5)
    EXPECT_EQ(result[1], 5);
}

TEST(Task2ExerciseTest, Execute)
{
    std::stringstream test_input;
    test_input << "1 12 3 21 10 8 7 11";
    auto stream_gen = std::make_unique<IStreamGenerator>(test_input);
    Task2Exercise exercise(8, std::move(stream_gen));
    
    exercise.execute();
    auto result = exercise.get_matrix();
    
    // Элементы с цифрой 1: 1, 12, 21, 10, 11 (5 элементов)
    // Исходный размер 8 + 5 = 13
    EXPECT_EQ(result.get_size(), 13);
    
    // Проверяем, что K=5 вставлено перед элементами с цифрой 1
    int k_count = 0;
    for (size_t i = 0; i < result.get_size(); ++i)
    {
        if (result[i] == 5) k_count++;
    }
    EXPECT_EQ(k_count, 5);
}

TEST(Task3ExerciseTest, Execute)
{
    std::stringstream test_input;
    test_input << "4 6 8 10";
    auto stream_gen = std::make_unique<IStreamGenerator>(test_input);
    Task3Exercise exercise(4, std::move(stream_gen));
    
    exercise.execute();
    auto result = exercise.get_matrix();
    
    // Проверяем преобразование по формулам
    EXPECT_EQ(result[0], 4);   // 4/1 = 4
    EXPECT_EQ(result[1], 18);  // 6^2/2 = 36/2 = 18
    EXPECT_EQ(result[2], 3);   // 8/3 ≈ 3
    EXPECT_EQ(result[3], 25);  // 10^2/4 = 100/4 = 25
}

TEST(ConstantGeneratorTest, Generate)
{
    ConstantGenerator generator(7);
    EXPECT_EQ(generator.generate(), 7);
    EXPECT_EQ(generator.generate(), 7);
    EXPECT_EQ(generator.generate(), 7);
}

TEST(IStreamGeneratorTest, Generate)
{
    std::stringstream test_input;
    test_input << "10 20 30";
    
    IStreamGenerator generator(test_input);
    EXPECT_EQ(generator.generate(), 10);
    EXPECT_EQ(generator.generate(), 20);
    EXPECT_EQ(generator.generate(), 30);
}
