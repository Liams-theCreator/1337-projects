#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc == 2)
        ScalarConverter::converter(argv[1]);
    else
        std::cout << "Enter at least one argument\n";
    return 0;
}