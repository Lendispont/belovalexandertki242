#pragma once
#include <memory>
#include <string>
#include <stdexcept>

namespace miit::algebra
{
    template<typename T>
    class Matrix
    {
    private:
        std::unique_ptr<T[]> data;
        size_t size;

    public:
        Matrix() : size(0), data(nullptr) {}
        
        Matrix(size_t size) : size(size), data(std::make_unique<T[]>(size)) {}
        
        Matrix(const Matrix& other) : size(other.size), data(std::make_unique<T[]>(other.size))
        {
            for (size_t i = 0; i < size; ++i)
            {
                data[i] = other.data[i];
            }
        }
        
        Matrix(Matrix&& other) noexcept : size(other.size), data(std::move(other.data))
        {
            other.size = 0;
        }
        
        ~Matrix() = default;
        
        Matrix& operator=(const Matrix& other)
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
        
        Matrix& operator=(Matrix&& other) noexcept
        {
            if (this != &other)
            {
                data = std::move(other.data);
                size = other.size;
                other.size = 0;
            }
            return *this;
        }
        
        Matrix operator<<(int shift) const
        {
            Matrix result(size);
            for (size_t i = 0; i < size; ++i)
            {
                result[(i + shift) % size] = data[i];
            }
            return result;
        }
        
        Matrix operator>>(int shift) const
        {
            Matrix result(size);
            for (size_t i = 0; i < size; ++i)
            {
                result[i] = data[(i + shift) % size];
            }
            return result;
        }
        
        T& operator[](size_t index)
        {
            if (index >= size) throw std::out_of_range("Index out of range");
            return data[index];
        }
        
        const T& operator[](size_t index) const
        {
            if (index >= size) throw std::out_of_range("Index out of range");
            return data[index];
        }
        
        // Методы доступа
        size_t get_size() const { return size; }
        
        void resize(size_t new_size)
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
        
        std::string to_string() const
        {
            std::string result = "[";
            for (size_t i = 0; i < size; ++i)
            {
                result += std::to_string(data[i]);
                if (i < size - 1) result += ", ";
            }
            result += "]";
            return result;
        }
        
        void fill_with_generator(class Generator& generator)
        {
            for (size_t i = 0; i < size; ++i)
            {
                data[i] = static_cast<T>(generator.generate());
            }
        }
    };
}
