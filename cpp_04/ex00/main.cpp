#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"
#include "WrongCat.hpp"

int main(void)
{
    std::cout << std::endl;
    std::cout << "~~~ ANIMAL ~~~" << std::endl;

    const Animal* meta = new Animal();

    std::cout << meta->getType() << std::endl;
    meta->makeSound();
    std::cout << std::endl;


    std::cout << "~~~ DOG ~~~" << std::endl;

    const Animal* j = new Dog();
    Animal* nonconst = new Dog();
    Dog* dog = new Dog();

    std::cout << j->getType() << std::endl;
    std::cout << nonconst->getType() << std::endl;
    std::cout << dog->getType() << std::endl;
    j->makeSound();
    nonconst->makeSound();
    dog->makeSound();
    std::cout << std::endl;


    std::cout << "~~~ CAT ~~~" << std::endl;

    const Animal* i = new Cat();
    Cat cat = Cat();
    const Cat* copy = new Cat(cat);
    const Animal* acopy = new Cat(cat);

    std::cout << i->getType() << std::endl;
    std::cout << cat.getType() << std::endl;
    std::cout << copy->getType() << std::endl;
    std::cout << acopy->getType() << std::endl;
    i->makeSound();
    cat.makeSound();
    copy->makeSound();
    acopy->makeSound();
    std::cout << std::endl;

    std::cout << "~~~ WRONG CAT ~~~" << std::endl;

    const WrongAnimal* animal_cat = new WrongCat();
    WrongCat cat_cat = WrongCat();

    animal_cat->makeSound();
    cat_cat.makeSound();
    std::cout << std::endl;

    delete (meta);
    delete (j);
    delete (nonconst);
    delete (dog);
    delete (i);
    delete (copy);
    delete (acopy);
    delete (animal_cat);

    return (0);
}