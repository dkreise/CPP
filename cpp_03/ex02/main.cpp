#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	ClapTrap clap("Clappp");
	ScavTrap scav("Scavvv");
	FragTrap frag("Fraggg");

	std::cout << "frag energy: " << frag.getEnergyP() << std::endl;
	std::cout << "scav energy: " << scav.getEnergyP() << std::endl;
	std::cout << "clap energy: " << clap.getEnergyP() << std::endl;

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