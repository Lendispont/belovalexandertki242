#pragma once

namespace miit::algebra
{
    /**
     * @brief Абстрактный генератор для заполнения массивов
     */
    class Generator
    {
    public:
        virtual ~Generator() = default;
        virtual int generate() = 0;
    };
}
