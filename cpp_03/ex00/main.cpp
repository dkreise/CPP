#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap first("First");
	ClapTrap second("Second");

	first.attack("Third");
	second.beRepaired(7);

	return (0);
}