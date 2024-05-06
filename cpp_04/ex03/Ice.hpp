#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria
{
    public:
        Ice(void);
        Ice(Ice const & src);
        ~Ice(void);

        Ice & operator=(Ice const & r);

        virtual AMateria* clone() const;
        virtual void use(ICharacter& target);
};

#endif