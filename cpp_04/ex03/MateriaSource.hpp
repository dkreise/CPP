#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    public:
        MateriaSource(void);
        MateriaSource(MateriaSource const & src);
        ~MateriaSource(void);

        MateriaSource & operator=(MateriaSource const & r);

        virtual void learnMateria(AMateria* materia);
        virtual AMateria* createMateria(std::string const & type);
        
    private:
        AMateria* _slots[4];
};

#endif 