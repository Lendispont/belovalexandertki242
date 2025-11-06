#pragma once
#include "Exercise.h"

namespace miit::algebra
{
    class Variant1Exercise : public Exercise
    {
    public:
        Variant1Exercise(size_t size, std::unique_ptr<Generator> gen);
        
        Matrix<int> Task1() override;
        Matrix<int> Task2() override;
        Matrix<int> Task3(const Matrix<int>& D) override;
        
    private:
        bool contains_digit_one(int number) const;
        int find_max_negative(const Matrix<int>& arr) const;
    };
}
