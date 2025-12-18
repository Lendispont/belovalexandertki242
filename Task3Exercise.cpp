#include "Task3Exercise.h"
#include <cmath>

namespace miit::algebra
{
    Task3Exercise::Task3Exercise(size_t size, std::unique_ptr<Generator> gen)
        : Exercise(size, std::move(gen)) {}

    void Task3Exercise::execute()
    {
        fill_matrix();
        
        Matrix<int> D = get_matrix();
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
        
        matrix = std::move(A);
    }
}
