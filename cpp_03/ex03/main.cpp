#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap di("Diamond");

	std::cout << "h.p.: " << di.getHitP() << " e.p.: " << di.getEnergyP() << " d.: " << di.getDamage() << std::endl;
	
	di.attack("victim");
	di.whoAmI();

	return (0);
}