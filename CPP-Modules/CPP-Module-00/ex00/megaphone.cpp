#include <iostream>
#include <string>

void str_upper(std::string &s)
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            s[i] -= 32;
            std::cout << s[i];
        }
        else
            std::cout << s[i];
    }
}

void error_msg()
{
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        error_msg();
        return 0;
    }
    for (int i = 1; i < argc; i++)
    {
        if (i > 1)
            std::cout << ' ';
        std::string str = argv[i];
        str_upper(str);
    }
    std::cout << '\n';
    return 0;
}