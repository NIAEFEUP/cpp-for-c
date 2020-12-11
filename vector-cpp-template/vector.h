#pragma once
#include <algorithm>
#include <cstddef>

template <class T>
class Vector
{
private:
    size_t _size;
    size_t capacity;
    T *data;
    static const size_t INITIAL_CAPACITY = 2;

public:
    Vector()
    {
        _size = 0;
        capacity = INITIAL_CAPACITY;
        data = new T[INITIAL_CAPACITY];
    }
    size_t size() const
    {
        return _size;
    }

    int get(size_t i, T &out) const
    {
        if (i < _size)
        {
            out = data[i];
            return 0;
        }
        else
            return -1;
    }

    void push_back(T n)
    {
        if (_size == capacity)
        {
            T *new_data = new T[capacity * 2];
            std::copy_n(data, _size, new_data);
            capacity *= 2;
            delete[] data;
            data = new_data;
        }
        data[_size++] = n;
    }

    ~Vector()
    {
        delete[] data;
    }
};
