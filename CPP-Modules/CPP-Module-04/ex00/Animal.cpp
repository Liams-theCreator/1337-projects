#include "Animal.hpp"

Animal::Animal()
{
    type = "Animal";
    std::cout << "Animal Default Constructor called\n";
}

Animal::Animal(std::string type)
{
    this->type = type;
    std::cout << "Animal Parametrized constructor called type-> " << type << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal Destructor called type-> " << type << std::endl;
}

Animal::Animal(const Animal &other): type(other.type)
{
    std::cout << "Animal Copy Constructor called\n";
}

Animal &Animal::operator=(const Animal &other)
{
    std::cout << "Animal Copy Assignment operator called\n";
    if (this != &other)
        type = other.type;
    return *this;
}

void Animal::makeSound() const
{
    std::cout << "Animal making sound\n";
}

std::string Animal::getType() const
{
    return type;
}