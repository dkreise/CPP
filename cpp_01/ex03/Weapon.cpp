#include <iostream>
#include "Weapon.hpp"

Weapon::Weapon(void) {}

Weapon::Weapon(std::string new_type)
{
    this->type = new_type;
}

Weapon::~Weapon(void) {}

std::string& Weapon::getType(void) // const..
{
    return (this->type);
}

void Weapon::setType(std::string new_type)
{
    this->type = new_type;
}