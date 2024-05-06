#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	std::cout << "--------------------------------------" << std::endl;

	FragTrap frag("Fraggg");
	ScavTrap scav("Scavvv");
	ClapTrap clap("Clappp");

	std::cout << "frag e.p.: " << frag.getEnergyP() << " h.p.: " << frag.getHitP() << " d.: " << frag.getDamage() << std::endl;
	std::cout << "scav e.p.: " << scav.getEnergyP() << " h.p.: " << scav.getHitP() << " d.: " << scav.getDamage() << std::endl;
	std::cout << "clap e.p.: " << clap.getEnergyP() << " h.p.: " << clap.getHitP() << " d.: " << clap.getDamage() << std::endl;
	std::cout << "--------------------------------------" << std::endl;

	frag.attack("victim");
	std::cout << "frag e.p.: " << frag.getEnergyP() << " h.p.: " << frag.getHitP() << std::endl;
	std::cout << "--------------------------------------" << std::endl;

	frag.beRepaired(3);
	std::cout << "frag e.p.: " << frag.getEnergyP() << " h.p.: " << frag.getHitP() << std::endl;
	std::cout << "--------------------------------------" << std::endl;

	frag.takeDamage(300);
	std::cout << "frag e.p.: " << frag.getEnergyP() << " h.p.: " << frag.getHitP() << std::endl;
	frag.takeDamage(10);
	std::cout << "frag e.p.: " << frag.getEnergyP() << " h.p.: " << frag.getHitP() << std::endl;
	std::cout << "--------------------------------------" << std::endl;

	frag.highFivesGuys();
	std::cout << "frag e.p.: " << frag.getEnergyP() << " h.p.: " << frag.getHitP() << std::endl;
	std::cout << "--------------------------------------" << std::endl;

	FragTrap frag2(frag);
	std::cout << "frag e.p.: " << frag.getEnergyP() << " h.p.: " << frag.getHitP() << std::endl;
	std::cout << "frag2 e.p.: " << frag2.getEnergyP() << " h.p.: " << frag2.getHitP() << std::endl;
	frag2.attack("victim2");
	std::cout << "frag e.p.: " << frag.getEnergyP() << " h.p.: " << frag.getHitP() << std::endl;
	std::cout << "frag2 e.p.: " << frag2.getEnergyP() << " h.p.: " << frag2.getHitP() << std::endl;
	std::cout << "--------------------------------------" << std::endl;

	return (0);
}