#include "FragTrap.hpp"

int main()
{
    std::cout << "\n--- Creating FragTrap ---" << std::endl;
    FragTrap frag("Frag");

    std::cout << "\n--- Testing FragTrap attack ---" << std::endl;
    frag.attack("Target");

    std::cout << "\n--- Testing FragTrap takeDamage / beRepaired ---" << std::endl;
    frag.takeDamage(50);
    frag.beRepaired(30);

    std::cout << "\n--- Testing FragTrap highFivesGuys ---" << std::endl;
    frag.highFivesGuys();

    return 0;
}   