#include "vector.h"
#include "stdio.h"

int main(void) {
    vector_t *vec = vector_new();
    vector_push_back(vec, 13);
    vector_push_back(vec, 42);
    vector_push_back(vec, 666);
    for (size_t i = 0; i < vector_size(vec); i++) {
        int n;
        vector_get(vec, i, &n);
        printf("%d\n", n);
    }
    return 0;
}
