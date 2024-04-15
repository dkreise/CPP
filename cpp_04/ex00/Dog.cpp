#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(Dog const & src)
{
    // ...
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog(void)
{
    std::cout << "Dog destructor called" << std::endl;
}

Dog & Dog::operator=(Dog const & r)
{
    // ...
    return (*this);
}

void Dog::makeSound(void)
{
    std::cout << "Woof" << std::endl; //meow for cat
}