#pragma once
#include <stddef.h>

typedef struct __vector vector_t;

vector_t *vector_new();

size_t vector_size(vector_t *vec);

int vector_get(vector_t *vec, size_t i, int *out);

void vector_push_back(vector_t *vec, int n);

void vector_destroy(vector_t *vec);
