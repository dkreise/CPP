#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	ClapTrap clap("Clappp");
	ScavTrap scav("Scavvv");
	FragTrap frag("Fraggg");

	std::cout << "frag e.p.: " << frag.getEnergyP() << std::endl;
	std::cout << "scav e.p.: " << scav.getEnergyP() << std::endl;
	std::cout << "clap e.p.: " << clap.getEnergyP() << std::endl;

	clap.attack("victim");
	scav.attack("victim");
	frag.attack("victim");
	std::cout << "frag e.p.: " << frag.getEnergyP() << std::endl;
	std::cout << "scav e.p.: " << scav.getEnergyP() << std::endl;
	std::cout << "clap e.p.: " << clap.getEnergyP() << std::endl;

	clap.beRepaired(7);
	scav.beRepaired(70);
	frag.beRepaired(3);
	std::cout << "frag h.p.: " << frag.getHitP() << std::endl;
	std::cout << "scav h.p.: " << scav.getHitP() << std::endl;
	std::cout << "clap h.p.: " << clap.getHitP() << std::endl;

	clap.takeDamage(10);
	std::cout << "clap h.p.: " << clap.getHitP() << std::endl;
	clap.takeDamage(10);
	std::cout << "clap h.p.: " << clap.getHitP() << std::endl;

	frag.takeDamage(300);
	std::cout << "frag h.p.: " << frag.getHitP() << std::endl;
	frag.takeDamage(10);
	std::cout << "frag h.p.: " << frag.getHitP() << std::endl;
	std::cout << "frag e.p.: " << frag.getEnergyP() << std::endl;
	

	frag.highFivesGuys();

	FragTrap frag2(frag);
	std::cout << "frag2 h.p.: " << frag2.getHitP() << std::endl;
	std::cout << "frag2 e.p.: " << frag2.getEnergyP() << std::endl;
	frag2.attack("victim2");
	std::cout << "frag2 h.p.: " << frag2.getHitP() << std::endl;
	std::cout << "frag2 e.p.: " << frag2.getEnergyP() << std::endl;
	std::cout << "frag h.p.: " << frag.getHitP() << std::endl;
	std::cout << "frag e.p.: " << frag.getEnergyP() << std::endl;

	return (0);
}