#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"

int main(void)
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    Animal* nonconst = new Dog();
    Dog* dog = new Dog();
    const Animal* i = new Cat();

    // add cats!
    // copy ctors check

    std::cout << meta->getType() << std::endl;
    std::cout << j->getType() << std::endl;
    std::cout << i->getType() << std::endl;
    std::cout << nonconst->getType() << std::endl;
    std::cout << dog->getType() << std::endl;
    j->makeSound();
    i->makeSound();
    meta->makeSound();
    nonconst->makeSound();
    dog->makeSound();

    delete (meta);
    delete (j);
    delete (i);
    delete (nonconst);
    delete (dog);
    return (0);
}