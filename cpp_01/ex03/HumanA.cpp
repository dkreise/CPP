#include <iostream>
#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string name, Weapon w) //there was an error
{
    this->name = name;
    this->weapon = w;
}

HumanA::~HumanA(void) {}

void HumanA::attack(void)
{
    std::cout << this->name << " attacks with their " << this->weapon->type << std::endl;
}