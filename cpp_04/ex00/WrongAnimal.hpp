#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include <iostream>

class WrongAnimal
{
    public:
        WrongAnimal(void);
        WrongAnimal(WrongAnimal const & src);
        virtual ~WrongAnimal(void);

        WrongAnimal & operator=(WrongAnimal const & r);

        void makeSound(void) const;
        std::string getType(void) const;
        
    protected:
        WrongAnimal(std::string type);
        std::string type;
};

#endif