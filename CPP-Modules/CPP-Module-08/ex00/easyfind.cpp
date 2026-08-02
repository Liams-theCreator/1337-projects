#include "easyfind.hpp"

const char *NotFound::what() const throw()
{
    return "value not found\n";
}