#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap first("First");
	ClapTrap second("Second");

	for (int i = 0; i < 12; i ++)
		first.attack("Third");

	second.beRepaired(7);
	first.beRepaired(7);
	second.attack("someone");
	for (int i = 0; i < 5; i ++)
		second.takeDamage(5);
	second.beRepaired(42);
	for (int i = 0; i < 5; i ++)
		second.takeDamage(5);

	return (0);
}