#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(Dog const & src)
{
    *this = src;
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog(void)
{
    std::cout << "Dog destructor called" << std::endl;
}

Dog & Dog::operator=(Dog const & r)
{
    this->type = r.type;
    return (*this);
}

void Dog::makeSound(void) const
{
    std::cout << "Woof" << std::endl;
}