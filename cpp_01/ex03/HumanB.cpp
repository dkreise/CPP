#include <iostream>
#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string name)
{
    this->name = name;
    this->weapon = NULL;
}

HumanB::~HumanB(void) {}

void HumanB::attack(void)
{
    std::string w_type;

    if (this->weapon)
    {
        //std::cout << "WEAPON PTR IN ATTACK::: " << this->weapon << std::endl;
        w_type = this->weapon->getType();
        std::cout << this->name << " attacks with their ";
        std::cout << w_type << std::endl;
    }
    else
        std::cout << this->name << " is not armed now" << std::endl;
}

void HumanB::setWeapon(Weapon& w)
{
    this->weapon = &w;
    //std::cout << "WEAPON PTR IN SET::: " << this->weapon << std::endl;
}