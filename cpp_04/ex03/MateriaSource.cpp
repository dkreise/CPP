#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
    for (int i = 0; i < 4; i ++)
        this->_slots[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const & src)
{
    for (int i = 0; i < 4; i ++)
    {
        if (src._slots[i] != NULL)
            this->_slots[i] = src._slots[i]->clone();
        else
            this->_slots[i] = NULL;
    }
}

MateriaSource::~MateriaSource(void)
{
    for (int i = 0; i < 4; i ++)
    {
        if (this->_slots[i] != NULL)
            delete (this->_slots[i]);
    }
}

MateriaSource & MateriaSource::operator=(MateriaSource const & r)
{
    if (this != &r)
    {
        for (int i = 0; i < 4; i ++)
        {
            if (this->_slots[i] != NULL)
                delete (this->_slots[i]);
            if (r._slots[i] != NULL)
                this->_slots[i] = r._slots[i]->clone();
            else
                this->_slots[i] = NULL;
        }
    }
    return (*this);
}

void MateriaSource::learnMateria(AMateria* materia)
{
    int i = 0;
    while (this->_slots[i] != NULL)
        i ++;
    if (i >= 4)
        return ;
    this->_slots[i] = materia;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i ++)
    {
        if (this->_slots[i] != NULL)
        {
            if (this->_slots[i]->getType().compare(type) == 0)
                return (this->_slots[i]->clone());
        }
    }
    return (0);
}