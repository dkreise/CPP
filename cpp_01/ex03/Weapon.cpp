#include <iostream>
#include "Weapon.hpp"

Weapon::Weapon(void) {}

Weapon::~Weapon(void) {}

std::string& const Weapon::getType(void)
{
    return (this->type);
}

void Weapon::setType(std::string new_type)
{
    this->type = new_type;
}