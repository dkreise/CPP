#include <iostream>
#include "Point.hpp"

/* 
Cross product of two vectors a and b = (a_y*b_z - a_z*b_y, a_z*b_x - a_x*b_z, a_x*b_y - a_y*b_x)
(on a plane a_z and b_z = 0)
Coordinates of vector AB: AB_x = B_x - A_x, AB_y = B_y - A_y
Is needed to calculate 3 cross products: ABxAP, BCxBP and CAxCP
and we are interested only on z-coordinate of them (others == 0)
if they are same direction (all three pos or neg) => the point is inside
if one is 0 and others same dir => the point is on edge
if two are 0 => point is a vertex
if there are different directions => the point is outside
*/

static Fixed cross_product(Point const &a, Point const &b, Point const &point)
{
	Fixed a_x = a.getX();
	Fixed a_y = a.getY();
	Fixed b_x = b.getX();
	Fixed b_y = b.getY();
	Fixed p_x = point.getX();
	Fixed p_y = point.getY();

	return ((b_x - a_x) * (p_y - a_y) - (b_y - a_y) * (p_x - a_x));
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed ab = cross_product(a, b, point);
	Fixed bc = cross_product(b, c, point);
	Fixed ca = cross_product(c, a, point);

	if ((ab > 0 && bc > 0 && ca > 0) || (ab < 0 && bc < 0 && ca < 0))
		return (true);
	else
		return (false);
}