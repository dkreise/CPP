#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>

class AAnimal
{
    public:
        AAnimal(void);
        AAnimal(AAnimal const & src);
        virtual ~AAnimal(void);

        AAnimal & operator=(AAnimal const & r);

        virtual void makeSound(void) const = 0;
        std::string getType(void) const;
        
    protected:
        AAnimal(std::string type);
        std::string type;
};

#endif