#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): name("noname"), hit_points(10), energy_points(10), attack_damage(0)
{
    std::cout << "ClapTrap Default constructor called\n";
}

ClapTrap::ClapTrap(std::string name): name(name), hit_points(10), energy_points(10), attack_damage(0)
{
    std::cout << "ClapTrap Parametrized constructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap &other): name(other.name), hit_points(other.hit_points), energy_points(other.energy_points), attack_damage(other.attack_damage)
{
    std::cout << "ClapTrap Copy constructor called\n";
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap Destructor called\n";
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    std::cout << "ClapTrap Copy assignment operator called\n";
    if (this != &other)
    {
        name = other.name;
        hit_points = other.hit_points;
        energy_points = other.energy_points;
        attack_damage = other.attack_damage;
    }
    return (*this);
}

void ClapTrap::attack(const std::string& target)
{
    if (this->hit_points != 0 && this->energy_points != 0)
    {
        std::cout << "ClapTrap [ " << this->name << " ] attacks [ " << target << " ] , Causing " << this->attack_damage << " Points of damage!\n";
        this->energy_points--;
    }
    else
        std::cout << "ClapTrap [ " << this->name << " ] Dont have enough hit/energy points to attack\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (amount >= this->hit_points)
        this->hit_points = 0;
    else
        this->hit_points -= amount;

    std::cout << "ClapTrap [ " << this->name << " ] Take " << amount << " of Damage ,and he has " << this->hit_points << " of hit points\n";
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->hit_points != 0 && this->energy_points != 0)
    {
        this->energy_points--;
        this->hit_points += amount;
        std::cout << "ClapTrap [ " << this->name << " ] repaired itself with " << amount << " hit points and it have now " << this->hit_points << " of his HP\n";
    }
    else
        std::cout << "ClapTrap [ " << this->name << " ] Dont have enough hit/energy points to repair\n";
}
