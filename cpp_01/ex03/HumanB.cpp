#include <iostream>
#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string name)
{
    this->_name = name;
    this->_weapon = NULL;
}

HumanB::~HumanB(void) {}

void HumanB::attack(void)
{
    std::string w_type;

    if (this->_weapon)
    {
        w_type = this->_weapon->getType();
        std::cout << this->_name << " attacks with their ";
        std::cout << w_type << std::endl;
    }
    else
        std::cout << this->_name << " is not armed now" << std::endl;
}

void HumanB::setWeapon(Weapon& w)
{
    this->_weapon = &w;
}