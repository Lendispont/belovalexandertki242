#pragma once
#include "Exercise.h"

namespace miit::algebra
{
    class Task1Exercise : public Exercise
    {
    private:
        int find_max_negative(const Matrix<int>& arr) const;
        
    public:
        Task1Exercise(size_t size, std::unique_ptr<Generator> gen);
        void execute() override;
    };
}
