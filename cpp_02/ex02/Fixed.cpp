#include <iostream>
#include <cmath>
#include "Fixed.hpp"

const int Fixed::_bits = 8;

Fixed::Fixed(void) : _num(0) {}

Fixed::Fixed(int const n)
{
	this->_num = n << _bits;
}

Fixed::Fixed(float const f)
{
	this->_num = roundf(f * (1 << _bits));
}

Fixed::Fixed(Fixed const & src)
{
	*this = src;
}

Fixed::~Fixed(void) {}

Fixed & Fixed::operator=(Fixed const & rhs)
{
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
    temp._num = ++(this->_num);
    return (temp);
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    ++(this->_num);
    return(temp);
}

Fixed Fixed::operator--(void)
{
    Fixed temp;
    temp._num = --(this->_num);
    return (temp);
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    --(this->_num);
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