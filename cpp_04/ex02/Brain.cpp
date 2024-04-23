#include "Brain.hpp"

Brain::Brain(void) : _ind(0), _last_ind(0)
{
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain & src)
{
	for (int i = 0; i < 100; i ++)
		this->_ideas[i] = src._ideas[i];
	this->_ind = src._ind;
	this->_last_ind = src._last_ind;
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain & Brain::operator=(const Brain & r)
{
	if (this != &r)
	{
		for (int i = 0; i < 100; i ++)
			this->_ideas[i] = r._ideas[i];
		this->_ind = r._ind;
		this->_last_ind = r._last_ind;
	}
	return (*this);
}

void Brain::printIdeas(void) const
{
	int last = this->_last_ind;
	if (last == 0)
		std::cout << "*no ideas*" << std::endl;
	for (int i = 0; i < last; i ++)
		std::cout << i + 1 << ". " << this->_ideas[i] << std::endl;
}

void Brain::addIdea(std::string idea)
{
	if (this->_ind == 100)
		this->_ind = 0;
	this->_ideas[this->_ind] = idea;
	this->_ind ++;
	this->_last_ind ++;
	if (this->_last_ind > 100)
		this->_last_ind = 100;
}