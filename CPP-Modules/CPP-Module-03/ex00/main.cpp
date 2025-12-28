#include "ClapTrap.hpp"

int main()
{
	ClapTrap user("Player 1");

	user.attack("Player 2");
	user.takeDamage(2);
	user.beRepaired(2);

	return 0;
}