#include "Dog.hpp"
#include "Animal.hpp"

int main(void)
{
     Animal* meta = new Animal(); // should work with const ..
     Animal* j = new Dog(); // also ..

    std::cout << j->getType() << std::endl;
    j->makeSound();
    meta->makeSound();

    return (0);
}