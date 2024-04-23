#include "Dog.hpp"

Dog::Dog(void) : AAnimal("Dog")
{
    this->_brain = new Brain();
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(Dog const & src) : AAnimal(src)
{
    this->_brain = new Brain(*src._brain);
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog(void)
{
    delete (this->_brain);
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

void Dog::printIdeas(void) const
{
    this->_brain->printIdeas();
}

void Dog::addIdea(std::string idea)
{
    this->_brain->addIdea(idea);
}