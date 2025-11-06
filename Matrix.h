#pragma once
#include <memory>
#include <string>

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
        Matrix(size_t size);
        Matrix(const Matrix& other);
        Matrix(Matrix&& other) noexcept;
        

        ~Matrix() = default;
        

        Matrix& operator=(const Matrix& other);
        Matrix& operator=(Matrix&& other) noexcept;
        

        Matrix operator<<(int shift) const;
        Matrix operator>>(int shift) const;
        

        T& operator[](size_t index);
        const T& operator[](size_t index) const;
        

        size_t get_size() const;
        void resize(size_t new_size);
        

        std::string to_string() const;
        

        void fill_with_generator(class Generator& generator);
    };
}
