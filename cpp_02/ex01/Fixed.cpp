#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed(void) : _num(0); _bits(8)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const n)
{
	std::cout << "Int constructor called" << std::endl;
	
}

Fixed::Fixed(float const f)
{
	std::cout << "Float constructor called" << std::endl;

}

Fixed::Fixed(Fixed const & src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed & Fixed::operator=(Fixed const & rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_num = rhs.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_num);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_num = raw;
}





std::ostream & operator<<(std::ostream & o, Fixed const & i)
{
	//o << "the value of llalala " << i.get....;
	return (o);
}