#include "Array.hpp"
#include <iostream>
#include <string>

int main()
{
    Array<int> empty;
    std::cout << "empty size: " << empty.size() << std::endl;

    Array<int> a(5);
    for (unsigned int i = 0; i < a.size(); i++)
        a[i] = i * 10;
    std::cout << "a:";
    for (unsigned int i = 0; i < a.size(); i++)
        std::cout << " " << a[i];
    std::cout << std::endl;

    Array<int> b(a);
    a[0] = 999;
    std::cout << "after a[0]=999 -> a[0]=" << a[0] << " b[0]=" << b[0] << std::endl;

    try 
    { 
        a[42] = 1; 
    }
    catch (std::exception &e) 
    {
        std::cout << "caught: " << e.what() << std::endl; 
    }

    Array<std::string> s(2);
    s[0] = "hello";
    s[1] = "array";
    std::cout << s[0] << " " << s[1] << std::endl;

    return 0;
}
