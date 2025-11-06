#pragma once
#include <gtest/gtest.h>
#include <sstream>
#include "ProblemSolution.h"
#include "IStreamGenerator.h"

using namespace miit::algebra;

class ExerciseTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        std::stringstream test_input;
        test_input << "1 -5 3 -2 10 -8 7 -1";
        auto stream_gen = std::make_unique<IStreamGenerator>(test_input);
        exercise = std::make_unique<Variant1Exercise>(8, std::move(stream_gen));
        exercise->fill_matrix();
    }
    
    std::unique_ptr<Variant1Exercise> exercise;
};

TEST_F(ExerciseTest, Task1_ReplaceSecondWithMaxNegative)
{
    auto result = exercise->Task1();
    EXPECT_EQ(result[1], -1);
}

TEST_F(ExerciseTest, Task2_InsertKBeforeOnes)
{
    auto result = exercise->Task2();
    EXPECT_EQ(result.get_size(), 11);
    
    bool found_k_before_1 = false;
    bool found_k_before_10 = false;
    bool found_k_before_negative_1 = false;
    
    for (size_t i = 0; i < result.get_size() - 1; ++i)
    {
        if (result[i] == 5 && result[i + 1] == 1) found_k_before_1 = true;
        if (result[i] == 5 && result[i + 1] == 10) found_k_before_10 = true;
        if (result[i] == 5 && result[i + 1] == -1) found_k_before_negative_1 = true;
    }
    
    EXPECT_TRUE(found_k_before_1);
    EXPECT_TRUE(found_k_before_10);
    EXPECT_TRUE(found_k_before_negative_1);
}

TEST_F(ExerciseTest, Task3_TransformArray)
{
    Matrix<int> D(4);
    D[0] = 4; D[1] = 6; D[2] = 8; D[3] = 10;
    
    auto result = exercise->Task3(D);
    
    EXPECT_EQ(result[0], 4);
    EXPECT_EQ(result[1], 18);
    EXPECT_EQ(result[2], 3);
    EXPECT_EQ(result[3], 25);
}

TEST_F(ExerciseTest, ContainsDigitOne)
{
    Variant1Exercise ex(1, std::make_unique<RandomGenerator>(1, 1));
    
    EXPECT_TRUE(ex.contains_digit_one(1));
    EXPECT_TRUE(ex.contains_digit_one(10));
    EXPECT_TRUE(ex.contains_digit_one(21));
    EXPECT_TRUE(ex.contains_digit_one(-15));
    EXPECT_TRUE(ex.contains_digit_one(100));
    
    EXPECT_FALSE(ex.contains_digit_one(2));
    EXPECT_FALSE(ex.contains_digit_one(35));
    EXPECT_FALSE(ex.contains_digit_one(0));
    EXPECT_FALSE(ex.contains_digit_one(-7));
}

TEST_F(ExerciseTest, FindMaxNegative)
{
    Matrix<int> test_arr(6);
    test_arr[0] = 1; test_arr[1] = -3; test_arr[2] = 5;
    test_arr[3] = -1; test_arr[4] = -8; test_arr[5] = 2;
    
    Variant1Exercise ex(1, std::make_unique<RandomGenerator>(1, 1));
    int max_negative = ex.find_max_negative(test_arr);
    
    EXPECT_EQ(max_negative, -1);
}

TEST_F(ExerciseTest, FindMaxNegative_NoNegatives)
{
    Matrix<int> test_arr(3);
    test_arr[0] = 1; test_arr[1] = 3; test_arr[2] = 5;
    
    Variant1Exercise ex(1, std::make_unique<RandomGenerator>(1, 1));
    int max_negative = ex.find_max_negative(test_arr);
    
    EXPECT_EQ(max_negative, 0);
}
