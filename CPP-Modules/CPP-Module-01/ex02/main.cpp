#include <iostream>

int main(void)
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << "Address of str variable     : " << &str << std::endl;
    std::cout << "Address held by ptr variable: " << stringPTR << std::endl;
    std::cout << "Address held by ref variable: " << &stringREF << std::endl;
    std::cout << "-----------------------------" << std::endl;
    std::cout << str << std::endl;
    std::cout << *stringPTR << std::endl;
    std::cout << stringREF << std::endl;
    return 0;
}