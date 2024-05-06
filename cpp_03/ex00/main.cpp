#include "ClapTrap.hpp"

int main(void)
{
	std::cout << "--------------------------------------" << std::endl;

	ClapTrap first("First");
	ClapTrap second("Second");
	std::cout << "1 : h.p.: " << first.getHitP() << " e.p.: " << first.getEnergyP() << " d.: " << first.getDamage() << std::endl;
	std::cout << "2 : h.p.: " << second.getHitP() << " e.p.: " << second.getEnergyP() << " d.: " << second.getDamage() << std::endl;
	std::cout << "--------------------------------------" << std::endl;

	for (int i = 0; i < 12; i ++)
	{
		first.attack("victim");
		std::cout << "h.p.: " << first.getHitP() << " e.p.: " << first.getEnergyP() << " d.: " << first.getDamage() << std::endl;
	}
	std::cout << "--------------------------------------" << std::endl;

	second.beRepaired(7);
	std::cout << "2 : h.p.: " << second.getHitP() << " e.p.: " << second.getEnergyP() << " d.: " << second.getDamage() << std::endl;
	first.beRepaired(7);
	std::cout << "1 : h.p.: " << first.getHitP() << " e.p.: " << first.getEnergyP() << " d.: " << first.getDamage() << std::endl;
	std::cout << "--------------------------------------" << std::endl;

	second.attack("someone");
	for (int i = 0; i < 5; i ++)
	{
		second.takeDamage(5);
		std::cout << "h.p.: " << second.getHitP() << " e.p.: " << second.getEnergyP() << " d.: " << second.getDamage() << std::endl;
	}
	second.beRepaired(42);
	for (int i = 0; i < 5; i ++)
	{
		second.takeDamage(5);
		std::cout << "h.p.: " << second.getHitP() << " e.p.: " << second.getEnergyP() << " d.: " << second.getDamage() << std::endl;
	}
	std::cout << "--------------------------------------" << std::endl;

	ClapTrap third(second);
	std::cout << "second h.p.: " << second.getHitP() << std::endl;
	std::cout << "third h.p.: " << third.getHitP() << std::endl;
	second.beRepaired(3);
	std::cout << "second h.p.: " << second.getHitP() << std::endl;
	std::cout << "third h.p.: " << third.getHitP() << std::endl;
	std::cout << "--------------------------------------" << std::endl;

	third = second;
	std::cout << "second h.p.: " << second.getHitP() << std::endl;
	std::cout << "third h.p.: " << third.getHitP() << std::endl;
	third.beRepaired(3);
	std::cout << "second h.p.: " << second.getHitP() << std::endl;
	std::cout << "third h.p.: " << third.getHitP() << std::endl;
	std::cout << "--------------------------------------" << std::endl;

	return (0);
}