#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <exception>
#include <algorithm>
#include <list>
#include <vector>

class NotFound : public std::exception
{
    public:
        const char *what() const throw();
};

template <typename T>
typename T::iterator easyfind(T &container, int val)
{
    typename T::iterator it = std::find(container.begin(), container.end(), val);
    if (it == container.end())
        throw NotFound();
    return it;
}


#endif