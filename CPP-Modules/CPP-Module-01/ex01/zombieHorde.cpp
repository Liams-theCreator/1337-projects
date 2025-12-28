#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    if (N <= 0)
        return NULL;
    Zombie *horde = new Zombie[6];
    int i = 0;
    for ( ; i < N; i++)
        horde[i].setName(name);
    return horde;
}