#include "vector_class.h"

Vector::Vector()
{
    _size = 0;
    capacity = INITIAL_CAPACITY;
    data = new int[INITIAL_CAPACITY];
}
size_t Vector::size() const
{
    return _size;
}

int Vector::get(size_t i, int &out) const
{
    if (i < _size)
    {
        out = data[i];
        return 0;
    }
    else
        return -1;
}

void Vector::push_back(int n)
{
    if (_size == capacity)
    {
        int *new_data = new int[capacity * 2];
        std::copy_n(data, _size, new_data);
        capacity *= 2;
        delete[] data;
        data = new_data;
    }
    data[_size++] = n;
}

Vector::~Vector()
{
    delete[] data;
}
