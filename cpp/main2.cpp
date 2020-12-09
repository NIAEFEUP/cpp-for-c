#include <iostream>
#include <vector>

int main(void)
{
    std::vector<int> vec;
    vec.push_back(13);
    vec.push_back(42);
    vec.push_back(666);
    for (auto n : vec)
    {
        std::cout << n << "\n";
    }
}
