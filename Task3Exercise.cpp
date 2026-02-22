#include "Task3Exercise.h"
#include <cmath>

namespace miit::algebra
{
    Task3Exercise::Task3Exercise(size_t size, std::unique_ptr<Generator> gen)
        : Exercise(size, std::move(gen)) {}

    void Task3Exercise::execute()
    {
        matrix.fill_with_generator(*generator);

        Matrix<int> A(matrix.get_size());
        for (size_t i = 0; i < matrix.get_size(); ++i)
        {
            size_t index = i + 1;
            if (index % 2 == 0)
                A[i] = static_cast<int>(std::round(static_cast<double>(matrix[i] * matrix[i]) / index));
            else
                A[i] = static_cast<int>(std::round(static_cast<double>(matrix[i]) / index));
        }
        matrix = std::move(A);
    }
}
