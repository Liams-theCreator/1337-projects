#include "Cat.hpp"

Cat::Cat() : AbsAnimal("Cat") 
{
    brain = new Brain();
    std::cout << "Cat Default Constructor called\n";
}

Cat::~Cat() 
{
    delete brain;
    std::cout << "Cat Destructor called\n";
}

Cat &Cat::operator=(const Cat &other) 
{
    std::cout << "Cat Copy Assignment Operator called\n";
    if (this != &other) {
        AbsAnimal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

Cat::Cat(const Cat &other) : AbsAnimal(other) 
{
    brain = new Brain(*other.brain);
    std::cout << "Cat Copy Constructor called\n";
}

void Cat::makeSound() const 
{
    std::cout << "Meow\n";
}
