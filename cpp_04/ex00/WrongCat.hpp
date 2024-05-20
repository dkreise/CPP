#ifndef WRONG_CAT_HPP
#define WRONG_CAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    public: 
        WrongCat(void);
        WrongCat(WrongCat const & src);
        virtual ~WrongCat(void);

        WrongCat & operator=(WrongCat const & r);

        void makeSound(void) const;
};

#endif