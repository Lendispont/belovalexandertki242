#include "Task1Exercise.h"

namespace miit::algebra
{
    Task1Exercise::Task1Exercise(size_t size, std::unique_ptr<Generator> gen)
        : Exercise(size, std::move(gen)) {}

    void Task1Exercise::execute()
    {
        matrix.fill_with_generator(*generator);

        if (matrix.get_size() >= 2)
        {
            int max_negative = find_max_negative(matrix);
            if (max_negative != 0)
                matrix[1] = max_negative;
        }
    }

    int Task1Exercise::find_max_negative(const Matrix<int>& arr) const
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
