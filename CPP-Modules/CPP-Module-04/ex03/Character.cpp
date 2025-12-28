#include "Character.hpp"

Character::Character(std::string const & name) : name(name) 
{
    int i = 0 ;
    for ( ; i < 4; i++)
        inventory[i] = NULL;
}

Character::Character(Character const & other) : name(other.name) 
{
    int i = 0;
    for ( ; i < 4; i++) 
    {
        if (other.inventory[i])
            inventory[i] = other.inventory[i]->clone();
        else
            inventory[i] = NULL;
    }
}

Character &Character::operator=(Character const & other) 
{
    if (this != &other) 
    {
        name = other.name;
        int i = 0;
        for ( ; i < 4; i++) 
        {
            delete inventory[i];
            if (other.inventory[i])
                inventory[i] = other.inventory[i]->clone();
            else
                inventory[i] = NULL;
        }
    }
    return *this;
}

Character::~Character() 
{
    int i = 0;
    for ( ; i < 4; i++)
        delete inventory[i];
}

std::string const & Character::getName() const 
{
    return name;
}

void Character::equip(AMateria* m) 
{
    int i = 0;
    for ( ; i < 4; i++) 
    {
        if (!inventory[i]) 
        {
            inventory[i] = m;
            break;
        }
    }
}

void Character::unequip(int idx) 
{
    if (idx >= 0 && idx < 4)
        inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) 
{
    if (idx >= 0 && idx < 4 && inventory[idx])
        inventory[idx]->use(target);
}