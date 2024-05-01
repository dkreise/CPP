#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap clap("Clappp");
	ScavTrap scav("Scavvv");

	std::cout << "clap e.p.: " << clap.getEnergyP() << std::endl;
	std::cout << "scav e.p.: " << scav.getEnergyP() << std::endl;
	std::cout << "clap h.p.: " << clap.getHitP() << std::endl;
	std::cout << "scav h.p.: " << scav.getHitP() << std::endl;

	clap.attack("victim");
	scav.attack("victim");
	std::cout << "clap e.p.: " << clap.getEnergyP() << std::endl;
	std::cout << "scav e.p.: " << scav.getEnergyP() << std::endl;

	clap.beRepaired(7);
	scav.beRepaired(70);
	std::cout << "clap e.p.: " << clap.getEnergyP() << std::endl;
	std::cout << "scav e.p.: " << scav.getEnergyP() << std::endl;
	std::cout << "clap h.p.: " << clap.getHitP() << std::endl;
	std::cout << "scav h.p.: " << scav.getHitP() << std::endl;

	clap.takeDamage(100);
	std::cout << "clap h.p.: " << clap.getHitP() << std::endl;
	clap.takeDamage(10);
	std::cout << "clap h.p.: " << clap.getHitP() << std::endl;

	scav.takeDamage(100);
	std::cout << "scav h.p.: " << scav.getHitP() << std::endl;
	scav.takeDamage(100);
	std::cout << "scav h.p.: " << scav.getHitP() << std::endl;

	clap.attack("victim");
	scav.attack("victim");

	std::cout << "clap e.p.: " << clap.getEnergyP() << std::endl;
	std::cout << "scav e.p.: " << scav.getEnergyP() << std::endl;
	std::cout << "clap h.p.: " << clap.getHitP() << std::endl;
	std::cout << "scav h.p.: " << scav.getHitP() << std::endl;

	ScavTrap scav2(scav);
	std::cout << "scav e.p.: " << scav.getEnergyP() << std::endl;
	std::cout << "scav2 e.p.: " << scav2.getEnergyP() << std::endl;
	scav2.attack("victim2");
	std::cout << "scav e.p.: " << scav.getEnergyP() << std::endl;
	std::cout << "scav2 e.p.: " << scav2.getEnergyP() << std::endl;

	return (0);
}