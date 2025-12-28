#include "Dog.hpp"

Dog::Dog(): Animal("Dog")
{
    brain = new Brain();
    std::cout << "Dog Default constructor called\n";
}

Dog::~Dog()
{
    delete brain;
    std::cout << "Dog Destructor called\n";
}

Dog &Dog::operator=(const Dog &other)
{
    std::cout << "Dog Copy assignment operator called\n";
    if (this != &other) 
    {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

Dog::Dog(const Dog &other): Animal(other)
{
    brain = new Brain(*other.brain);
    std::cout << "Dog Copy constructor called\n";
}

void Dog::makeSound() const
{
    std::cout << "Haw Haw\n";
}

void Dog::setBrianIdea(int idx, const std::string &idea)
{
    brain->setIdea(idx, idea);
}
std::string Dog::getBrainIdea(int idx) const
{
    return brain->getIdea(idx);
}
