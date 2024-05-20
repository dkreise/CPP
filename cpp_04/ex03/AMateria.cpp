#include "AMateria.hpp"

AMateria::AMateria(void) : _isEquipped(0) {}

AMateria::AMateria(std::string const & type) : _type(type), _isEquipped(0) {}

AMateria::~AMateria(void) {}

AMateria & AMateria::operator=(AMateria const & r)
{
    (void)r;
    return (*this);
}

std::string const & AMateria::getType(void) const
{
    return (this->_type);
}

unsigned int AMateria::getStatusEquipped(void) const
{
    return (this->_isEquipped);
}

void AMateria::setStatusEquipped(unsigned int val)
{
    this->_isEquipped = val;
}