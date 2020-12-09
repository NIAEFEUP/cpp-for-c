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
    Vector();

    size_t size() const;

    int get(size_t i, int &out) const;

    void push_back(int n);

    ~Vector();
};
