#include "ScavTrap.hpp"

int main()
{
    std::cout << "--- Creating ScavTraps ---\n";
    ScavTrap scav("Scav");

    std::cout << "\n--- Testing ScavTrap attack ---\n";
    scav.attack("Player");

    std::cout << "\n--- Testing ScavTraps takeDamage / beRepaired ---\n";
    scav.takeDamage(50);
    scav.beRepaired(30);

    std::cout << "\n--- Testing ScavTrap guardGate ---\n";
    scav.guardGate();

    return 0;
}