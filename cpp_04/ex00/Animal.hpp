#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
    public:
        Animal(void);
        Animal(Animal const & src);
        ~Animal(void);

        Animal & operator=(Animal const & r);

        virtual void makeSound(void);
        std::string const getType(void);
    protected:
        Animal(std::string type);
        std::string type;
};

#endif