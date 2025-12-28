#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap("noname")
{
    std::cout << "ScavTrap Default constructor called\n";
    this->hit_points = 100;
    this->energy_points = 50;
    this->attack_damage = 20;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
    std::cout << "ScavTrap Parametrized constructor called\n";
    this->hit_points = 100;
    this->energy_points = 50;
    this->attack_damage = 20; 
}

ScavTrap::ScavTrap(const ScavTrap &other): ClapTrap(other)
{
    std::cout << "ScavTrap Copy constructor called\n";
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    std::cout << "ScavTrap Copy assignment operator called\n";
    if (this != &other)
        ClapTrap::operator=(other);
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor called \n";
}

void ScavTrap::attack(const std::string& target)
{
    if (this->hit_points != 0 && this->energy_points != 0)
    {
        std::cout << "ScavTrap [ " << this->name << " ] attacks [ " << target << " ] , Causing " << this->attack_damage << " Points of damage!\n";
        this->energy_points--;
    }
    else
        std::cout << "ScavTrap [ " << this->name << " ] Dont have enough hit/energy points to attack\n";
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap is now in Gate keeper mode\n";
}
