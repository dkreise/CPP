#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
    public: 
        Cat(void);
        Cat(Cat const & src);
        ~Cat(void);

        Cat & operator=(Cat const & r);

        virtual void makeSound(void) const;
        virtual void printIdeas(void) const;
        void addIdea(std::string idea);
        
    private:
        Brain* _brain;
};

#endif