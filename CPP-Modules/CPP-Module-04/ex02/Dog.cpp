#include "Dog.hpp"

Dog::Dog(): AbsAnimal("Dog")
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
    if (this != &other) {
        AbsAnimal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

Dog::Dog(const Dog &other): AbsAnimal(other)
{
    brain = new Brain(*other.brain);
    std::cout << "Dog Copy constructor called\n";
}

void Dog::makeSound() const
{
    std::cout << "Haw Haw\n";
}