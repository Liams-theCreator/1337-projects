#include <iostream>
#include "iter.hpp"

template <typename T>
void print(T const &x)
{
    std::cout << x << std::endl;
}

int main(void)
{
    int intArr[] = {0, 1, 2, 3, 4};
    ::iter(intArr, 5, print<int>);

    const int constArr[] = {42, 42, 42, 42, 42};
    ::iter(constArr, 5, print<int>);

    return 0;
}
