#include <iostream>
#include <cmath>
#include "Fixed.hpp"

const int Fixed::_bits = 8;

Fixed::Fixed(void) : _num(0)
{
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const n)
{
	//std::cout << "Int constructor called" << std::endl;
	this->_num = n << _bits;
}

Fixed::Fixed(float const f)
{
	//std::cout << "Float constructor called" << std::endl;
	this->_num = roundf(f * (1 << _bits));
}

Fixed::Fixed(Fixed const & src)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed(void)
{
	//std::cout << "Destructor called" << std::endl;
}

Fixed & Fixed::operator=(Fixed const & rhs)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_num = rhs.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const
{
	return (this->_num);
}

void Fixed::setRawBits(int const raw)
{
	this->_num = raw;
}

float Fixed::toFloat(void) const
{
	return(static_cast<float>(this->_num) / (1 << _bits));
}

int Fixed::toInt(void) const
{
	return (static_cast<int>(this->_num >> _bits));
}

bool Fixed::operator>(Fixed const & rhs) const
{
    return (this->_num > rhs.getRawBits());
}

bool Fixed::operator<(Fixed const & rhs) const
{
    return (this->_num < rhs.getRawBits());
}

bool Fixed::operator>=(Fixed const & rhs) const
{
    return (this->_num >= rhs.getRawBits());
}

bool Fixed::operator<=(Fixed const & rhs) const
{
    return (this->_num <= rhs.getRawBits());
}

bool Fixed::operator==(Fixed const & rhs) const
{
    return (this->_num == rhs.getRawBits());
}

bool Fixed::operator!=(Fixed const & rhs) const
{
    return (this->_num != rhs.getRawBits());
}

Fixed Fixed::operator+(Fixed const & rhs) const
{
    return (this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(Fixed const & rhs) const
{
    return (this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(Fixed const & rhs) const
{
    return (this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(Fixed const & rhs) const
{
    return (this->toFloat() / rhs.toFloat());
}

Fixed Fixed::operator++(void)
{
    Fixed temp;
    temp._num = ++this->_num;
    return (temp);
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    ++this->_num;
    return(temp);
}

Fixed Fixed::operator--(void)
{
    Fixed temp;
    temp._num = --this->_num;
    return (temp);
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    --this->_num;
    return(temp);
}

Fixed & Fixed::min(Fixed & a, Fixed & b)
{
    if (a.getRawBits() < b.getRawBits())
        return (a);
    else
        return (b);
}

Fixed const & Fixed::min(Fixed const & a, Fixed const & b)
{
    if (a.getRawBits() < b.getRawBits())
        return (a);
    else
        return (b);
}

Fixed & Fixed::max(Fixed & a, Fixed & b)
{
    if (a.getRawBits() > b.getRawBits())
        return (a);
    else
        return (b);
}

Fixed const & Fixed::max(Fixed const & a, Fixed const & b)
{
    if (a.getRawBits() > b.getRawBits())
        return (a);
    else
        return (b);
}

std::ostream & operator<<(std::ostream & o, Fixed const & i)
{
	o << i.toFloat();
	return (o);
}