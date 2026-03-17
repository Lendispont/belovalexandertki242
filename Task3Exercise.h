#pragma once
#include "Exercise.h"

namespace miit::algebra
{
    class Task3Exercise : public Exercise
    {
    public:
        Task3Exercise(size_t size, std::unique_ptr<Generator> gen);
        void execute() override;
    };
}
