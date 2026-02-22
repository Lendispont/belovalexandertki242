#include "Task2Exercise.h"
#include <cmath>

namespace miit::algebra
{
    const int Task2Exercise::K = 5;

    Task2Exercise::Task2Exercise(size_t size, std::unique_ptr<Generator> gen)
        : Exercise(size, std::move(gen)) {}

    void Task2Exercise::execute()
    {

        matrix.fill_with_generator(*generator);

        size_t count_ones = 0;
        for (size_t i = 0; i < matrix.get_size(); ++i)
            if (contains_digit_one(matrix[i]))
                ++count_ones;

        Matrix<int> result(matrix.get_size() + count_ones);
        size_t result_index = 0;
        for (size_t i = 0; i < matrix.get_size(); ++i)
        {
            if (contains_digit_one(matrix[i]))
                result[result_index++] = K;
            result[result_index++] = matrix[i];
        }
        matrix = std::move(result);
    }

    bool Task2Exercise::contains_digit_one(int number) const
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
}
