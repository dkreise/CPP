#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
    this->_brain = new Brain();
    std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(Cat const & src) : Animal(src)
{
    this->_brain = new Brain(*src._brain);
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat(void)
{
    delete (this->_brain);
    std::cout << "Cat destructor called" << std::endl;
}

Cat & Cat::operator=(Cat const & r)
{
    std::cout << "Cat copy assignment operator called" << std::endl;
    // if (this->brain) ??????????????
    delete (this->_brain);
    this->_brain = new Brain(*r._brain);
    this->type = r.type;
    return (*this);
}

void Cat::makeSound(void) const
{
    std::cout << "Meow" << std::endl;
}

void Cat::printIdeas(void) const
{
    this->_brain->printIdeas();
}

void Cat::addIdea(std::string idea)
{
    this->_brain->addIdea(idea);
}