#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("Cat")
{
    std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const & src)
{
    *this = src;
    std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat::~WrongCat(void)
{
    std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat & WrongCat::operator=(WrongCat const & r)
{
    this->type = r.type;
    return (*this);
}

void WrongCat::makeSound(void) const
{
    std::cout << "Meow" << std::endl;
}