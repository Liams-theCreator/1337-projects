#include "Zombie.hpp"

Zombie::Zombie(std::string Zombiename)
{
    name = Zombiename;
}

Zombie::~Zombie()
{
    std::cout << name << ": Dead!" << std::endl;
}

void Zombie::announce()
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}