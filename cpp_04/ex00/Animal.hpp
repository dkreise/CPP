#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
    public:
        Animal(void);
        Animal(Animal const & src);
        virtual ~Animal(void); // check leaks without

        Animal & operator=(Animal const & r);

        virtual void makeSound(void) const;
        std::string getType(void) const;
    protected:
        Animal(std::string type);
        std::string type;
};

#endif