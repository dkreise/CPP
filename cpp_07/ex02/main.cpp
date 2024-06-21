#include "Array.hpp"

int main(void)
{
    Array<int> a;
    std::cout << a.size() << std::endl;

    Array<int> b(42);
    std::cout << b.size() << std::endl;
    std::cout << b[7] << std::endl;

    Array<std::string> c(3);
    std::cout << c.size() << std::endl;
    std::cout << c[1] << std::endl;

    Array<char> d(7);
    std::cout << d.size() << std::endl;
    d[0] = 'k';
    std::cout << d[0] << std::endl;
}