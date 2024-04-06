#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap clap("Clappp");
	ScavTrap scav("Scavvv");

	clap.attack("victim");
	scav.attack("victim");

	clap.beRepaired(7);
	scav.beRepaired(70);

	clap.takeDamage(100);
	clap.takeDamage(10);
	clap.attack("victim");

	scav.takeDamage(1000);
	scav.takeDamage(10);
	scav.attack("victim");

	return (0);
}