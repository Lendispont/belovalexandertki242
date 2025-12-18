#pragma once
#include "Exercise.h"

namespace miit::algebra
{
    class Task2Exercise : public Exercise
    {
    private:
        bool contains_digit_one(int number) const;
        static const int K = 5;
        
    public:
        Task2Exercise(size_t size, std::unique_ptr<Generator> gen);
        void execute() override;
    };
}
