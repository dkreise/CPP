#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
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