// Developed by Handziur Dmytro on 29.03.2026
#pragma once
#include <cstddef>
#include <stdexcept>
#include <string>
#include <utility>

template<typename T>
class Array {
public:
    // Creates empty array (no memory allocated)
    explicit Array(std::size_t capacity = 0)
        : _capacity(capacity)
        , _size(0)
        , _data(capacity ? new T[capacity] : nullptr)
    {}

    ~Array() { delete[] _data; }

    Array(const Array&) = delete;
    Array& operator=(const Array&) = delete;

    // ---- State ----
    std::size_t size()     const { return _size; }
    std::size_t capacity() const { return _capacity; }
    bool        empty()    const { return _size == 0; }

    // ---- Access ----
    const T& operator[](std::size_t i) const {
        if (i >= _size)
            throw std::out_of_range("Array: index " + std::to_string(i)
                + " >= size " + std::to_string(_size));
        return _data[i];
    }

    // ---- Modification ----

    void push_back(const T& x)
    {
        if (_size == _capacity) _grow();

        _data[_size++] = x;
    }

    bool remove_first(const T& x)
    {
        for (size_t i = 0; i < _size; i++)
        {
            if (_data[i] == x)
            {
                for (size_t j = i; j < _size - 1; j++)
                {
                    _data[j] = _data[j + 1];
                }

                _size--;
                
                return true;
            }
        }

        return false;
    }

    bool contains(const T& x) const
    {
        for (size_t i = 0; i < _size; i++)
        {
            if (_data[i] == x) return true;
        }

        return false;
    }

    friend std::ostream& operator<<(std::ostream& os, const Array<T>& arr)
    {
        os << "[ ";
        for (std::size_t i = 0; i < arr.size(); i++)
        {
            os << arr[i] << " ";
        }
        os << "]";
        return os;
    }

private:
    std::size_t _capacity;
    std::size_t _size;
    T* _data;

    void _grow()
    {
        size_t new_capacity = _capacity * 2 + 1;
        T* new_data = new T[new_capacity];

        for (size_t i = 0; i < _size; i++)
        {
            new_data[i] = std::move(_data[i]);
        }

        delete[] _data;

        _data = new_data;
        _capacity = new_capacity;
    }
};
