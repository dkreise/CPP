#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    public: 
        Dog(void);
        Dog(Dog const & src);
        virtual ~Dog(void);

        Dog & operator=(Dog const & r);

        virtual void makeSound(void) const;
        virtual void printIdeas(void) const;
        void addIdea(std::string idea);
        
    private:
        Brain* _brain;
};

#endif