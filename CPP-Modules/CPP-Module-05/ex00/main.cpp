#include "Bureaucrat.hpp"

int main() 
{
    try
    {
        Bureaucrat b("Bob", 0);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception -> " << e.what();
    }

    try
    {
        Bureaucrat b("Charlie", 151);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception -> " << e.what();
    }

    try
    {
        Bureaucrat b("Dave", 1);
        b.increment();
    }
    catch (std::exception &e)
    {
        std::cout << "Exception -> " << e.what();
    }

    try
    {
        Bureaucrat b("Eve", 150);
        b.decrement();
    }
    catch (std::exception &e)
    {
        std::cout << "Exception -> " << e.what();
    }
    return 0;
}