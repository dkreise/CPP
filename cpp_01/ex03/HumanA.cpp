#include <iostream>
#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string name, Weapon& w) : name(name), weapon(w)  //there was an error
{

}

HumanA::~HumanA(void) {}

void HumanA::attack(void)
{
    std::string w_type;

    w_type = this->weapon.getType();
    std::cout << this->name << " attacks with their " << w_type << std::endl;
}