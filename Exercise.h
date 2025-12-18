#pragma once
#include "Matrix.h"
#include "Generator.h"
#include <memory>

namespace miit::algebra
{
    class Exercise
    {
    protected:
        Matrix<int> matrix;
        std::unique_ptr<Generator> generator;

    public:
        Exercise(size_t size, std::unique_ptr<Generator> gen);
        virtual ~Exercise() = default;
        void fill_matrix();
        Matrix<int> get_matrix() const;
        virtual void execute() = 0;
    };
}
