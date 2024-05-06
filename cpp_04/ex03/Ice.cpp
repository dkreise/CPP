#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice")
{
    std::cout << "Ice constructor called" << std::endl;
}

// copy ctor

Ice::~Ice(void)
{
    std::cout << "Ice destructor called" << std::endl;
}

// operator=

AMateria* Ice::clone() const
{
    return (new Ice());
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}