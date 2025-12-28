#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap("noname") {
    std::cout << "FragTrap Default constructor called\n";
    this->hit_points = 100;
    this->energy_points = 100;
    this->attack_damage = 30;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
    std::cout << "FragTrap Parametrized constructor called\n";
    this->hit_points = 100;
    this->energy_points = 100;
    this->attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap &other): ClapTrap(other)
{
    std::cout << "FragTrap Copy constructor called\n";
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
    std::cout << "FragTrap Copy assignment operator called\n";
    if (this != &other)
        ClapTrap::operator=(other);
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Destructor called\n";
}

void FragTrap::attack(const std::string& target)
{
    if (this->hit_points != 0 && this->energy_points != 0)
    {
        std::cout << "FragTrap [ " << this->name << " ] attacks [ " << target << " ] , Causing " << this->attack_damage << " Points of damage!\n";
        this->energy_points--;
    }
    else
    {
        std::cout << "FragTrap [ " << this->name << " ] doesn't have enough hit points or energy to attack\n";
    }
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap [ " << this->name << " ] requests a positive high five!\n";
}