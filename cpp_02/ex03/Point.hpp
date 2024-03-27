#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

class Point
{
	public:
		Point(void);
		Point(float const x, float const y);
		Point(Point const & src);
		~Point(void);

		Point & operator=(Point const & rhs);

		Fixed getX(void) const;
		Fixed getY(void) const;

	private:
		Fixed const _x;
		Fixed const _y;
};

std::ostream & operator<<(std::ostream & o, Point const & i);

#endif