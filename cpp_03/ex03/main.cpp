#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap di("Diamonddd");

	std::cout << "h.p.: " << di.getHitP() << " e.p.: " << di.getEnergyP() << " d.: " << di.getDamage() << std::endl;
	
	di.attack("victim");
	std::cout << "h.p.: " << di.getHitP() << " e.p.: " << di.getEnergyP() << " d.: " << di.getDamage() << std::endl;

	di.takeDamage(7);
	std::cout << "h.p.: " << di.getHitP() << " e.p.: " << di.getEnergyP() << " d.: " << di.getDamage() << std::endl;

	di.beRepaired(42);
	std::cout << "h.p.: " << di.getHitP() << " e.p.: " << di.getEnergyP() << " d.: " << di.getDamage() << std::endl;

	di.whoAmI();

	std::cout << "--------------------------------------" << std::endl;

	DiamondTrap di2(di);
	std::cout << "whoAmI() of Di2:" << std::endl;
	di2.whoAmI();
	std::cout << "Di : h.p.: " << di.getHitP() << " e.p.: " << di.getEnergyP() << " d.: " << di.getDamage() << std::endl;
	std::cout << "Di2 : h.p.: " << di2.getHitP() << " e.p.: " << di2.getEnergyP() << " d.: " << di2.getDamage() << std::endl;

	di.takeDamage(10);
	di2.beRepaired(100);
	std::cout << "Di : h.p.: " << di.getHitP() << " e.p.: " << di.getEnergyP() << " d.: " << di.getDamage() << std::endl;
	std::cout << "Di2 : h.p.: " << di2.getHitP() << " e.p.: " << di2.getEnergyP() << " d.: " << di2.getDamage() << std::endl;

	return (0);
}