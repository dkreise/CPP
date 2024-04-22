#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
    public: 
        Dog(void);
        Dog(Dog const & src);
        ~Dog(void);

        Dog & operator=(Dog const & r);

        virtual void makeSound(void) const;
        //std::string getType(void) const;
};

#endif