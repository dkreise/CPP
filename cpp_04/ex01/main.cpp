#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main(void)
{
    Cat cat = Cat();
    cat.makeSound();
    cat.printIdeas();
    cat.addIdea("im a cat");
    cat.printIdeas();
    for (int i = 0; i < 110; i ++)
        cat.addIdea("a");
    cat.printIdeas();
    for (int i = 0; i < 10; i ++)
        cat.addIdea("b");
    cat.printIdeas();

    const Animal* acat = new Cat();

    delete acat; // shouldn't be leaks

    return (0);
}