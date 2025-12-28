#include "Dog.hpp"

Dog::Dog(): Animal("Dog")
{
    std::cout << "Dog Default constructor called\n";
}

Dog::~Dog()
{
    std::cout << "Dog Destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
    std::cout << "Dog Copy assignment operator called\n";
    if (this != &other)
        type = other.type;
    return *this;
}

Dog::Dog(const Dog &other): Animal(other)
{
    std::cout << "Dog Copy constructor called\n";
}

void Dog::makeSound() const
{
    std::cout << "Haw Haw\n";
}