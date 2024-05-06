#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	std::cout << "--------------------------------------" << std::endl;

	ClapTrap clap("Clappp");
	ScavTrap scav("Scavvv");

	std::cout << "clap e.p.: " << clap.getEnergyP() << " h.p.: " << clap.getHitP() << " d.: " << clap.getDamage() << std::endl;
	std::cout << "scav e.p.: " << scav.getEnergyP() << " h.p.: " << scav.getHitP() << " d.: " << scav.getDamage() << std::endl;
	std::cout << "--------------------------------------" << std::endl;

	clap.attack("victim");
	scav.attack("victim");
	std::cout << "clap e.p.: " << clap.getEnergyP() << std::endl;
	std::cout << "scav e.p.: " << scav.getEnergyP() << std::endl;
	std::cout << "--------------------------------------" << std::endl;

	clap.beRepaired(7);
	scav.beRepaired(70);
	std::cout << "clap e.p.: " << clap.getEnergyP() << " h.p.: " << clap.getHitP() << std::endl;
	std::cout << "scav e.p.: " << scav.getEnergyP() << " h.p.: " << scav.getHitP() << std::endl;
	std::cout << "--------------------------------------" << std::endl;

	clap.takeDamage(100);
	std::cout << "clap h.p.: " << clap.getHitP() << std::endl;
	clap.takeDamage(10);
	std::cout << "clap h.p.: " << clap.getHitP() << std::endl;

	scav.takeDamage(100);
	std::cout << "scav h.p.: " << scav.getHitP() << std::endl;
	scav.takeDamage(100);
	std::cout << "scav h.p.: " << scav.getHitP() << std::endl;
	std::cout << "--------------------------------------" << std::endl;

	clap.attack("victim");
	scav.attack("victim");

	std::cout << "clap e.p.: " << clap.getEnergyP() << " h.p.: " << clap.getHitP() << std::endl;
	std::cout << "scav e.p.: " << scav.getEnergyP() << " h.p.: " << scav.getHitP() << std::endl;
	std::cout << "--------------------------------------" << std::endl;

	scav.guardGate();
	std::cout << "scav e.p.: " << scav.getEnergyP() << " h.p.: " << scav.getHitP() << std::endl;
	std::cout << "--------------------------------------" << std::endl;

	ScavTrap scav2(scav);
	std::cout << "scav e.p.: " << scav.getEnergyP() << std::endl;
	std::cout << "scav2 e.p.: " << scav2.getEnergyP() << std::endl;
	scav2.attack("victim2");
	std::cout << "scav e.p.: " << scav.getEnergyP() << std::endl;
	std::cout << "scav2 e.p.: " << scav2.getEnergyP() << std::endl;
	std::cout << "--------------------------------------" << std::endl;

	scav2 = scav;
	std::cout << "scav e.p.: " << scav.getEnergyP() << std::endl;
	std::cout << "scav2 e.p.: " << scav2.getEnergyP() << std::endl;
	scav2.attack("victim2");
	std::cout << "scav e.p.: " << scav.getEnergyP() << std::endl;
	std::cout << "scav2 e.p.: " << scav2.getEnergyP() << std::endl;
	std::cout << "--------------------------------------" << std::endl;

	return (0);
}