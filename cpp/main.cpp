#include <iostream>
#include "vector.h"

int main(void) {
    Vector vec;
    vec.push_back(13);
    vec.push_back(42);
    vec.push_back(666);
    for (size_t i = 0; i < vec.size(); i++) {
        int n;
        vec.get(i, n);
        std::cout << n << "\n";
    }   
    return 0;
}