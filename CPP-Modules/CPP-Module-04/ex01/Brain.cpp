#include "Brain.hpp"

Brain::Brain() 
{
    std::cout << "Brain Default Constructor called\n";
    int i = 0;
    for ( ; i < 100; i++)
        ideas[i] = "idea";
}

Brain::Brain(const Brain &other) 
{
    std::cout << "Brain Copy Constructor called\n";
    int i = 0;
    for ( ; i < 100; i++)
        ideas[i] = other.ideas[i];
}

Brain &Brain::operator=(const Brain &other) 
{
    std::cout << "Brain Copy Assignment Operator called\n";
    if (this != &other)
    {
        int i = 0;
        for ( ; i < 100; i++)
            ideas[i] = other.ideas[i];
    }
    return *this;
}

Brain::~Brain() 
{
    std::cout << "Brain Destructor called\n";
}

const std::string &Brain::getIdea(int index) const 
{
    return ideas[index];
}

void Brain::setIdea(int index, const std::string &idea) 
{
    ideas[index] = idea;
}