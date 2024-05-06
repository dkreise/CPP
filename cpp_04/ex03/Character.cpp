#include "Character.hpp"

Character::Character(void)
{
    for (int i = 0; i < 4; i ++)
        this->_slots[i] = nullptr;
    std::cout << "Character constructor called" << std::endl;
}

Character::Character(std::string name) : _name(name)
{
    for (int i = 0; i < 4; i ++)
        this->_slots[i] = nullptr;
    std::cout << "Character constructor called" << std::endl;
}

// copy ctor

Character::~Character(void)
{
    std::cout << "Character destructor called" << std::endl;
}

std::string const & Character::getName(void) const
{
    return (this->_name);
}

void Character::equip(AMateria* m)
{
    for (int i = 0; i < 4; i ++)
    {
        if (this->_slots[i] == nullptr)
        {
            this->_slots[i] = m;
            break;
        }
    }
}

void Character::unequip(int idx)
{
    this->_slots[idx] = nullptr;
}

void Character::use(int idx, ICharacter& target)
{
    this->_slots[idx]->use(target);
}