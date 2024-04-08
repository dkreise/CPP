#include <iostream>
#include "Fixed.hpp"

int main(void)
{
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;

    std::cout << Fixed::max(a, b) << std::endl;

    std::cout << "----------------------" << std::endl;

    Fixed c(1.011f);
    Fixed d(7.3333f);

    std::cout << "c: " << c << "   d: " << d << std::endl;
    std::cout << "INT: c: " << c.toInt() << "   d: " << d.toInt() << std::endl;
    std::cout << "min: " << Fixed::min(c, d) << std::endl;
    if (c < d)
        std::cout << "c < d" << std::endl;
    if (c > d)
        std::cout << "c > d" << std::endl;
    if (c == d)
        std::cout << "c == d" << std::endl;
    std::cout << "c + d = " << c + d << std::endl;

    std::cout << "1.5 * 4 = " << Fixed(1.5f) * Fixed(4) << std::endl;
    std::cout << "1 / 3 = " << Fixed(1) / Fixed(3) << std::endl;

    return (0);
}