#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
    std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(Cat const & src)
{
    *this = src;
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat(void)
{
    std::cout << "Cat destructor called" << std::endl;
}

Cat & Cat::operator=(Cat const & r)
{
    this->type = r.type;
    return (*this);
}

void Cat::makeSound(void) const
{
    std::cout << "Meow" << std::endl;
}