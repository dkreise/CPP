#include "AAnimal.hpp"

AAnimal::AAnimal(void)
{
    std::cout << "AAnimal constructor called" << std::endl;
}

AAnimal::AAnimal(std::string type)
{
    this->type = type;
    std::cout << "AAnimal constructor called" << std::endl;
}

AAnimal::AAnimal(AAnimal const & src)
{
    this->type = src.type;
    std::cout << "AAnimal copy constructor called" << std::endl;
}

AAnimal::~AAnimal(void)
{
    std::cout << "AAnimal destructor called" << std::endl;
}

AAnimal & AAnimal::operator=(AAnimal const & r)
{
    this->type = r.type;
    return (*this);
}

std::string AAnimal::getType(void) const
{
    return (this->type);
}