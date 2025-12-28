#include "Zombie.hpp"

int main(void)
{
    int i = 0;
    int size = 5;
    std::string name = "skeletons";

    Zombie *horde = zombieHorde(size, name);
    if (!horde)
        return -1;
    for ( ; i < size; i++)
        horde[i].announce();
    
    delete [] horde;
    return 0;
}
