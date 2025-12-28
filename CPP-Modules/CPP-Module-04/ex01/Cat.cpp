#include "Cat.hpp"

Cat::Cat() : Animal("Cat") 
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
    if (this != &other) 
    {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

Cat::Cat(const Cat &other) : Animal(other) 
{
    brain = new Brain(*other.brain);
    std::cout << "Cat Copy Constructor called\n";
}

void Cat::makeSound() const 
{
    std::cout << "Meow\n";
}

void Cat::setBrianIdea(int idx, const std::string &idea)
{
    brain->setIdea(idx, idea);
}
std::string Cat::getBrainIdea(int idx) const
{
    return brain->getIdea(idx);
}