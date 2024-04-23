#include "AAnimal.hpp"
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

    // Following code is not working because AAnimal is an abstract class now
    // AAnimal a = AAnimal();
    // a.makeSound();

    AAnimal* a = new Cat();
    a->makeSound();
    delete a;

    return (0);
}