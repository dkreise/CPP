#include "AMateria.hpp"

AMateria::AMateria(void)
{
    std::cout << "AMateria constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type)
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