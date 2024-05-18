#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice") {}

Ice::Ice(Ice const & src) : AMateria("ice")
{
    (void)src;
}

Ice::~Ice(void) {}

Ice & Ice::operator=(Ice const & r)
{
    std::cout << "ice = called" << std::endl;
    (void)r;
    return (*this);
}

AMateria* Ice::clone(void) const
{
    return (new Ice());
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}