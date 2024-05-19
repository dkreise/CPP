#include "Character.hpp"

Character::Character(void)
{
    for (int i = 0; i < 4; i ++)
        this->_slots[i] = NULL;
    //std::cout << "Character constructor called" << std::endl;
}

Character::Character(std::string name) : _name(name)
{
    for (int i = 0; i < 4; i ++)
        this->_slots[i] = NULL;
    //std::cout << "Character constructor called" << std::endl;
}

Character::Character(Character const & src)
{
    this->_name = src.getName();
    for (int i = 0; i < 4; i ++)
    {
        this->_slots[i] = NULL;
        if (src._slots[i])
            this->_slots[i] = src._slots[i]->clone();
    }
}

Character::~Character(void)
{
    for (int i = 0; i < 4; i ++)
    {
        if (this->_slots[i])
        {
            delete (this->_slots[i]);
            this->_slots[i] = NULL;
        }
    }
}

Character & Character::operator=(Character const & r)
{
    std::cout << "Character '=' called" << std::endl;
    if (this != &r)
    {
        this->_name = r.getName();
        for (int i = 0; i < 4; i ++)
        {
            if (this->_slots[i])
                delete (this->_slots[i]);
            this->_slots[i] = r._slots[i]->clone();

        }
    }
    return(*this);
}

std::string const & Character::getName(void) const
{
    return (this->_name);
}

void Character::equip(AMateria* m)
{
    if (m->getStatusEquipped() != 0)
    {
        std::cout << "This materia is already equipped by some Character!" << std::endl;
        return;
    }
    int i = 0;
    while (i < 4 && this->_slots[i] != NULL)
        i ++;
    if (i >= 4)
        return;
    this->_slots[i] = m;
    m->setStatusEquipped(1);
}

void Character::unequip(int idx)
{
    if (idx >= 4)
        return ;
    if (this->_slots[idx] != NULL)
    {
        this->_slots[idx]->setStatusEquipped(0);
        this->_slots[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 4)
        return ;
    if (this->_slots[idx] != NULL)
        this->_slots[idx]->use(target);
    // else
    //     std::cout << "is nullll" << std::endl;
}