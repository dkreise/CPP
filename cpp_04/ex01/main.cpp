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

    std::cout << "--------------------------------------" << std::endl;
    const Animal* acat = new Cat();

    delete acat; // shouldn't be leaks

    std::cout << "--------------------------------------" << std::endl;

    // Animal as[] = {Cat(), Dog()}; --- working

    Cat *c1 = new Cat();
    Cat *c2 = new Cat();
    Animal *c3 = new Cat();
    Dog *d1 = new Dog();
    Dog *d2 = new Dog();
    Animal *d3 = new Dog();

    Animal *a[] = {c1, c2, c3, d1, d2, d3};
    for (int i = 0; i < 6; i ++)
    {
        a[i]->makeSound();
        delete a[i];
    }

    std::cout << "--------------------------------------" << std::endl;

    // Cat cat1 = Cat();
    // // Cat cat1();  ---- not working...
    // Animal animals[] = {cat1};

    // Animal cat1 = Cat();
    // //Dog dog1(), dog2(), dog3();
    // Animal *animals2[] = {&cat1};

    return (0);
}