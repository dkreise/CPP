#include "AMateria.hpp"

AMateria::AMateria(void) : _isEquipped(0)
{
    std::cout << "AMateria constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type), _isEquipped(0)
{
    std::cout << "AMateria constructor called" << std::endl;
}

// copy ctor

AMateria::~AMateria(void)
{
    std::cout << "AMateria desctructor called" << std::endl;
}

// operator= overload

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