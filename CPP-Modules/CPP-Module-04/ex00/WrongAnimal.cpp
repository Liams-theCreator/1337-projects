#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    type = "WrongAnimal";
    std::cout << "WrongAnimal Default Constructor called\n";
}

WrongAnimal::WrongAnimal(std::string type)
{
    this->type = type;
    std::cout << "WrongAnimal Parametrized constructor called type-> " << type << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal Destructor called type-> " << type << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other): type(other.type)
{
    std::cout << "WrongAnimal Copy Constructor called\n";
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
    std::cout << "WrongAnimal Copy Assignment operator called\n";
    if (this != &other)
        type = other.type;
    return *this;
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal making sound\n";
}

std::string WrongAnimal::getType() const
{
    return type;
}