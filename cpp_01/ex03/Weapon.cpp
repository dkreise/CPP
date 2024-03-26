#include <iostream>
#include "Weapon.hpp"

Weapon::Weapon(void) {}

Weapon::Weapon(std::string type)
{
    this->_type = type;
}

Weapon::~Weapon(void) {}

std::string const & Weapon::getType(void)
{
    return (this->_type);
}

void Weapon::setType(std::string type)
{
    this->_type = type;
}