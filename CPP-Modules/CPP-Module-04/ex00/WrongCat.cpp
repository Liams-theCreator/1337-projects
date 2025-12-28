#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal("WrongCat")
{
    std::cout << "WrongCat Default constructor called\n";
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat Destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
    std::cout << "WrongCat Copy assignment operator called\n";
    if (this != &other)
        WrongAnimal::operator=(other);
    return *this;
}

WrongCat::WrongCat(const WrongCat &other): WrongAnimal(other)
{
    std::cout << "WrongCat Copy constructor called\n";
}

void WrongCat::makeSound() const
{
    std::cout << "WrongMeow\n";
}