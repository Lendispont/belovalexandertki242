#include "ProblemSolution.h"
#include <cmath>
#include <algorithm>

namespace miit::algebra
{
    Variant1Exercise::Variant1Exercise(size_t size, std::unique_ptr<Generator> gen)
        : Exercise(size, std::move(gen)) {}

    Matrix<int> Variant1Exercise::Task1()
    {
        Matrix<int> result = matrix;
        
        if (result.get_size() >= 2)
        {
            int max_negative = find_max_negative(result);
            if (max_negative != 0)
            {
                result[1] = max_negative;
            }
        }
        
        return result;
    }

    Matrix<int> Variant1Exercise::Task2()
    {
        const int K = 5;
        size_t count_ones = 0;
        
        for (size_t i = 0; i < matrix.get_size(); ++i)
        {
            if (contains_digit_one(matrix[i]))
            {
                count_ones++;
            }
        }
        
        Matrix<int> result(matrix.get_size() + count_ones);
        size_t result_index = 0;
        
        for (size_t i = 0; i < matrix.get_size(); ++i)
        {
            if (contains_digit_one(matrix[i]))
            {
                result[result_index++] = K;
            }
            result[result_index++] = matrix[i];
        }
        
        return result;
    }

    Matrix<int> Variant1Exercise::Task3(const Matrix<int>& D)
    {
        Matrix<int> A(D.get_size());
        
        for (size_t i = 0; i < D.get_size(); ++i)
        {
            size_t index = i + 1;
            if (index % 2 == 0)
            {
                A[i] = static_cast<int>(std::round(static_cast<double>(D[i] * D[i]) / index));
            }
            else
            {
                A[i] = static_cast<int>(std::round(static_cast<double>(D[i]) / index));
            }
        }
        
        return A;
    }

    bool Variant1Exercise::contains_digit_one(int number) const
    {
        if (number == 0) return false;
        
        int num = std::abs(number);
        while (num > 0)
        {
            if (num % 10 == 1) return true;
            num /= 10;
        }
        return false;
    }

    int Variant1Exercise::find_max_negative(const Matrix<int>& arr) const
    {
        int max_negative = 0;
        bool found = false;
        
        for (size_t i = 0; i < arr.get_size(); ++i)
        {
            if (arr[i] < 0)
            {
                if (!found || arr[i] > max_negative)
                {
                    max_negative = arr[i];
                    found = true;
                }
            }
        }
        
        return found ? max_negative : 0;
    }
}
