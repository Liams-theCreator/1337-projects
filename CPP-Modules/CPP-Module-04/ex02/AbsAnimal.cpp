#include "AbsAnimal.hpp"

AbsAnimal::AbsAnimal(): type("AbsAnimal")
{
    std::cout << "AbsAnimal Default Constructor called\n";
}

AbsAnimal::AbsAnimal(std::string type)
{
    this->type = type;
    std::cout << "AbsAnimal Parametrized constructor called type-> " << type << std::endl;
}

AbsAnimal::~AbsAnimal()
{
    std::cout << "AbsAnimal Destructor called type-> " << type << std::endl;
}

AbsAnimal::AbsAnimal(const AbsAnimal &other): type(other.type)
{
    std::cout << "AbsAnimal Copy Constructor called\n";
}

AbsAnimal &AbsAnimal::operator=(const AbsAnimal &other)
{
    std::cout << "AbsAnimal Copy Assignment operator called\n";
    if (this != &other)
        type = other.type;
    return *this;
}

std::string AbsAnimal::getType() const
{
    return type;
}