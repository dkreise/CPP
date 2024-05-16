#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
    protected:
        std::string _type;
        unsigned int _isEquipped;

    public:
        AMateria(void);
        AMateria(std::string const & type);
        AMateria(AMateria const & src);
        ~AMateria(void);

        AMateria & operator=(AMateria const & r);

        std::string const & getType(void) const;

        virtual AMateria* clone(void) const = 0;
        virtual void use(ICharacter& target);
        unsigned int getStatusEquipped(void) const;
        void setStatusEquipped(unsigned int val);
};

#endif