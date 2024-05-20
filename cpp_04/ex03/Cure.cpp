#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure") {}

Cure::Cure(Cure const & src) : AMateria("cure")
{
    (void)src;
}

Cure::~Cure(void) {}

Cure & Cure::operator=(Cure const & r)
{
    (void)r;
    return (*this);
}

AMateria* Cure::clone(void) const
{
    return (new Cure());
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}