#include <iostream>
#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main(void)
{
	Weapon club = Weapon("crude spiked club");

	HumanA bob("Bob", club);
	bob.attack();
	club.setType("some other type of club");
	bob.attack();

	Weapon club2 = Weapon("crude spiked club");

	HumanB jim("Jim");
	//std::cout << "W NOW:: " << jim.weapon->getType() << std::endl;
	//jim.attack();
	jim.setWeapon(club2);
	jim.attack();
	club2.setType("some other type of club");
	//std::cout << "WEAPON PTR::: " << &club2 << std::endl;
	//std::cout << "TYPE NOW::: " << club2.getType() << std::endl;
	jim.attack();

	return (0);
}