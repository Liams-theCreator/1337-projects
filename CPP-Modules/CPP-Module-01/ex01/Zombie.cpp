#include "Zombie.hpp"

Zombie::Zombie() {};

Zombie::~Zombie()
{
    std::cout << name << ": Dead!" << std::endl;
}

void Zombie::announce()
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string zName)
{
    name = zName;
}
