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

	return (0);
}