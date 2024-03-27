#include "Point.hpp"

Point::Point(void): _x(Fixed(0)), _y(Fixed(0)) {}

Point::Point(float const x, float const y) : _x(Fixed(x)), _y(Fixed(y)) {}

Point::Point(Point const & src) : _x(src.getX()), _y(src.getY())
{
}

Point::~Point(void) {}

Point & Point::operator=(Point const & rhs)
{
	(void)rhs;
	return (*this);
}

Fixed Point::getX(void) const
{
	return(this->_x);
}

Fixed Point::getY(void) const
{
	return(this->_y);
}

std::ostream & operator<<(std::ostream & o, Point const & i)
{
	o << "(" << i.getX() << ", " << i.getY() << ")";
	return (o);
}