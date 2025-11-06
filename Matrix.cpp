#include "Matrix.h"
#include <sstream>
#include <stdexcept>

namespace miit::algebra
{
    template<typename T>
    Matrix<T>::Matrix() : size(0), data(nullptr) {}

    template<typename T>
    Matrix<T>::Matrix(size_t size) : size(size), data(std::make_unique<T[]>(size)) {}

    template<typename T>
    Matrix<T>::Matrix(const Matrix& other) : size(other.size), data(std::make_unique<T[]>(other.size))
    {
        for (size_t i = 0; i < size; ++i)
        {
            data[i] = other.data[i];
        }
    }

    template<typename T>
    Matrix<T>::Matrix(Matrix&& other) noexcept : size(other.size), data(std::move(other.data))
    {
        other.size = 0;
    }

    template<typename T>
    Matrix<T>& Matrix<T>::operator=(const Matrix& other)
    {
        if (this != &other)
        {
            auto new_data = std::make_unique<T[]>(other.size);
            for (size_t i = 0; i < other.size; ++i)
            {
                new_data[i] = other.data[i];
            }
            data = std::move(new_data);
            size = other.size;
        }
        return *this;
    }

    template<typename T>
    Matrix<T>& Matrix<T>::operator=(Matrix&& other) noexcept
    {
        if (this != &other)
        {
            data = std::move(other.data);
            size = other.size;
            other.size = 0;
        }
        return *this;
    }

    template<typename T>
    Matrix<T> Matrix<T>::operator<<(int shift) const
    {
        Matrix result(size);
        for (size_t i = 0; i < size; ++i)
        {
            result[(i + shift) % size] = data[i];
        }
        return result;
    }

    template<typename T>
    Matrix<T> Matrix<T>::operator>>(int shift) const
    {
        Matrix result(size);
        for (size_t i = 0; i < size; ++i)
        {
            result[i] = data[(i + shift) % size];
        }
        return result;
    }

    template<typename T>
    T& Matrix<T>::operator[](size_t index)
    {
        if (index >= size) throw std::out_of_range("Index out of range");
        return data[index];
    }

    template<typename T>
    const T& Matrix<T>::operator[](size_t index) const
    {
        if (index >= size) throw std::out_of_range("Index out of range");
        return data[index];
    }

    template<typename T>
    size_t Matrix<T>::get_size() const
    {
        return size;
    }

    template<typename T>
    void Matrix<T>::resize(size_t new_size)
    {
        auto new_data = std::make_unique<T[]>(new_size);
        size_t min_size = (new_size < size) ? new_size : size;
        
        for (size_t i = 0; i < min_size; ++i)
        {
            new_data[i] = data[i];
        }
        
        data = std::move(new_data);
        size = new_size;
    }

    template<typename T>
    std::string Matrix<T>::to_string() const
    {
        std::ostringstream oss;
        oss << "[";
        for (size_t i = 0; i < size; ++i)
        {
            oss << data[i];
            if (i < size - 1) oss << ", ";
        }
        oss << "]";
        return oss.str();
    }

    template<typename T>
    void Matrix<T>::fill_with_generator(Generator& generator)
    {
        for (size_t i = 0; i < size; ++i)
        {
            data[i] = static_cast<T>(generator.generate());
        }
    }

    // Явная инстанциация для int
    template class Matrix<int>;
}
