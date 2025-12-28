#include "Cat.hpp"

Cat::Cat(): Animal("Cat")
{
    std::cout << "Cat Default constructor called\n";
}

Cat::~Cat()
{
    std::cout << "Cat Destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
    std::cout << "Cat Copy assignment operator called\n";
    if (this != &other)
        type = other.type;
    return *this;
}

Cat::Cat(const Cat &other): Animal(other)
{
    std::cout << "Cat Copy constructor called\n";
}

void Cat::makeSound() const
{
    std::cout << "Meow\n";
}