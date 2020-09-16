#include <iostream>
#include "vector_template.h"

int main(void) {
    Vector<int> vec;
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