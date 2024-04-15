#include "Animal.hpp"

Animal::Animal(void)
{
    std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(std::string type)
{
    this->type = type;
    std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(Animal const & src)
{
    // copy constructor ..
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal::~Animal(void)
{
    std::cout << "Animal destructor called" << std::endl;
}

Animal & Animal::operator=(Animal const & r)
{
    // ...
    return (*this);
}

std::string const Animal::getType(void)
{
    return (this->type);
}

void Animal::makeSound(void)
{
    std::cout << "*no sound*" << std::endl;
}