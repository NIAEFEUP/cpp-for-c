#include "vector.h"
#include <stdlib.h>

static const size_t INITIAL_CAPACITY = 2;

struct __vector
{
    size_t size;
    size_t capacity;
    int *data;
};

vector_t *vector_new()
{
    void *alloc = calloc(INITIAL_CAPACITY, sizeof(int));
    vector_t *vec = (vector_t *)malloc(sizeof(vector_t));
    vec->size = 0;
    vec->capacity = INITIAL_CAPACITY;
    vec->data = (int *) alloc;
    return vec;
}

size_t vector_size(vector_t *vec)
{
    return vec->size;
}

int vector_get(vector_t *vec, size_t i, int *out)
{
    if (i >= vec->size)
        return -1;
    *out = vec->data[i];
    return 0;
}

void vector_push_back(vector_t *vec, int n)
{
    if (vec->size == vec->capacity)
    {
        vec->data = reallocarray(vec->data, vec->capacity * 2, sizeof(int));
        vec->capacity *= 2;
    }
    vec->data[vec->size++] = n;
}

void vector_destroy(vector_t *vec)
{
    free(vec->data);
    free(vec);
}
