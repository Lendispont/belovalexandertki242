#pragma once
#include <memory>
#include <string>
#include <stdexcept>
#include "Generator.h"

namespace miit::algebra
{
    template<typename T>
    class Matrix
    {
    private:
        std::unique_ptr<T[]> data;
        size_t size;                 

    public:
        Matrix();

        explicit Matrix(const size_t size);

        Matrix(const Matrix& other);

        Matrix(Matrix&& other) noexcept;

        ~Matrix() = default;

        Matrix& operator=(const Matrix& other);

        Matrix& operator=(Matrix&& other) noexcept;

        Matrix operator<<(const int shift) const;

        Matrix operator>>(const int shift) const;

        T& operator[](const size_t index);

        const T& operator[](const size_t index) const;

        size_t get_size() const;

        void resize(const size_t new_size);

        std::string to_string() const;

        void fill_with_generator(const Generator& generator);
    };
    #include "Matrix_impl.h"
}
