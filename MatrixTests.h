#pragma once
#include <gtest/gtest.h>
#include "Matrix.h"
#include "RandomGenerator.h"

using namespace miit::algebra;

class MatrixTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        test_matrix = Matrix<int>(5);
        for (size_t i = 0; i < 5; ++i)
        {
            test_matrix[i] = static_cast<int>(i + 1);
        }
    }
    
    Matrix<int> test_matrix;
};

TEST_F(MatrixTest, DefaultConstructor)
{
    Matrix<int> matrix;
    EXPECT_EQ(matrix.get_size(), 0);
}

TEST_F(MatrixTest, ParameterizedConstructor)
{
    Matrix<int> matrix(10);
    EXPECT_EQ(matrix.get_size(), 10);
}

TEST_F(MatrixTest, CopyConstructor)
{
    Matrix<int> copy = test_matrix;
    EXPECT_EQ(copy.get_size(), test_matrix.get_size());
    for (size_t i = 0; i < test_matrix.get_size(); ++i)
    {
        EXPECT_EQ(copy[i], test_matrix[i]);
    }
}

TEST_F(MatrixTest, MoveConstructor)
{
    Matrix<int> original = test_matrix;
    Matrix<int> moved = std::move(original);
    EXPECT_EQ(moved.get_size(), test_matrix.get_size());
    EXPECT_EQ(original.get_size(), 0);
}

TEST_F(MatrixTest, AssignmentOperator)
{
    Matrix<int> assigned;
    assigned = test_matrix;
    EXPECT_EQ(assigned.get_size(), test_matrix.get_size());
}

TEST_F(MatrixTest, IndexOperator)
{
    EXPECT_EQ(test_matrix[0], 1);
    EXPECT_EQ(test_matrix[2], 3);
    
    test_matrix[1] = 10;
    EXPECT_EQ(test_matrix[1], 10);
}

TEST_F(MatrixTest, IndexOperatorOutOfRange)
{
    EXPECT_THROW(test_matrix[10], std::out_of_range);
}

TEST_F(MatrixTest, ShiftLeftOperator)
{
    auto shifted = test_matrix << 2;
    EXPECT_EQ(shifted[0], 3);
    EXPECT_EQ(shifted[4], 2);
}

TEST_F(MatrixTest, ShiftRightOperator)
{
    auto shifted = test_matrix >> 1;
    EXPECT_EQ(shifted[0], 5);
    EXPECT_EQ(shifted[1], 1);
}

TEST_F(MatrixTest, ToString)
{
    std::string result = test_matrix.to_string();
    EXPECT_TRUE(result.find("1") != std::string::npos);
    EXPECT_TRUE(result.find("5") != std::string::npos);
}

TEST_F(MatrixTest, Resize)
{
    test_matrix.resize(3);
    EXPECT_EQ(test_matrix.get_size(), 3);
    
    test_matrix.resize(7);
    EXPECT_EQ(test_matrix.get_size(), 7);
}

TEST_F(MatrixTest, FillWithGenerator)
{
    Matrix<int> matrix(5);
    auto generator = std::make_unique<RandomGenerator>(1, 10);
    matrix.fill_with_generator(*generator);
    
    for (size_t i = 0; i < matrix.get_size(); ++i)
    {
        EXPECT_GE(matrix[i], 1);
        EXPECT_LE(matrix[i], 10);
    }
}
