#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(Point const &a, Point const &b, Point const &c, Point const &point);

void print_bsp(Point const a, Point const b, Point const c, Point const point)
{
	std::cout << std::endl;
	std::cout << "A = " << a << std::endl;
	std::cout << "B = " << b << std::endl;
	std::cout << "C = " << c << std::endl;
	std::cout << "P = " << point << std::endl;
	std::cout << "Is P inside of a triangle ABC?   ";
	if (bsp(a, b, c, point))
		std::cout << "yes" << std::endl;
	else
		std::cout << "no" << std::endl;
}

int main(void)
{
	print_bsp(Point(0, 0), Point(0, 2), Point(2, 2), Point(0, 1));
	print_bsp(Point(0, 0), Point(0, 3), Point(3, 3), Point(1, 2));
	print_bsp(Point(31, -87), Point(42, 1000), Point(0, 0), Point(1, 1));

	std::cout << std::endl;
	return (0);
}