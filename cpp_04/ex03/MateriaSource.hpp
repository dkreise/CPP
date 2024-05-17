#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource
{
    public:
        MateriaSource(void);
        MateriaSource(MateriaSource const & src);
        ~MateriaSource(void);

        MateriaSource & operator=(MateriaSource const & r);

        virtual void learnMateria(AMateria* materia) = 0;
        virtual AMateria* createMateria(std::string const & type) = 0;
    private:
        AMateria *_slots[4];
};

#endif 