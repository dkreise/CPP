#include <iostream>
#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string name, Weapon& w) : _name(name), _weapon(w) {}

HumanA::~HumanA(void) {}

void HumanA::attack(void)
{
    std::string w_type;

    w_type = this->_weapon.getType();
    std::cout << this->_name << " attacks with their " << w_type << std::endl;
}