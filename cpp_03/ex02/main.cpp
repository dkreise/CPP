#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	ClapTrap clap("Clappp");
	ScavTrap scav("Scavvv");
	FragTrap frag("Fraggg");;

	clap.attack("victim");
	scav.attack("victim");
	frag.attack("victim");

	clap.beRepaired(7);
	scav.beRepaired(70);
	frag.beRepaired(3);

	clap.takeDamage(100);
	clap.takeDamage(10);

	frag.takeDamage(300);
	frag.takeDamage(10);

	frag.highFivesGuys();

	FragTrap frag2(frag);
	frag2.attack("victim2");

	return (0);
}