#pragma once
#include <cstddef>
#include <cstdlib>
#include <optional>
#include <algorithm>

class Vector
{
private:
    size_t _size;
    size_t capacity;
    int *data;
    static const size_t INITIAL_CAPACITY = 2;
public:
    Vector() {
        _size = 0;
        capacity = INITIAL_CAPACITY;
        data = new int[INITIAL_CAPACITY];
    }
    size_t size() const
    {
        return _size;
    }

    int get(size_t i, int &out) const
    {
        if (i < _size)
        {
            out = data[i];
            return 0;
        }
        else
            return -1;
    }

    void push_back(int n) {
        if (_size == capacity) {
            int *new_data = new int[capacity*2];
            std::copy_n(data, _size, new_data);
            capacity *= 2;
            delete[] data;
            data = new_data;
        }
        data[_size++] = n;
    }

    ~Vector() {
        delete[] data;
    }
};
