#include <iostream>
#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string name)
{
    this->name = name;
}

HumanB::~HumanB(void) {}

void HumanA::attack(void)
{
    std::cout << this->name << " attacks with their " << this->weapon->type << std::endl;
}