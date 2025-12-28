#include "Zombie.hpp"

int main(void)
{
    std::cout << "Stack example" << '\n';
    randomChump("Stack Zombie");

    std::cout << "Heap example" << '\n';
    Zombie *zom = newZombie("Heap Zombie");
    zom->announce();
    delete zom;
    
    return 0;
}