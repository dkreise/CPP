#include "Array.hpp"

int main(void)
{
    Array<int> a;
    std::cout << std::endl << "Size of a[]: " << a.size() << std::endl;
    try
    {
        std::cout << "a[0] = " << a[0] << std::endl << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "ERROR: " << e.what() << std::endl << std::endl;
    }

    Array<int> b(42);
    std::cout << "Size of b[]: " << b.size() << std::endl;
    std::cout << "Before b[7] = " << b[7] << std::endl;
    for (unsigned int i = 0; i < b.size(); i ++)
        b[i] = i + 1;
    std::cout << "After b[7] = " << b[7] << std::endl << std::endl;

    Array<std::string> c(3);
    c[0] = "Hello";
    c[1] = "world";
    c[2] = "!!!";
    std::cout << "Size of c[]: " << c.size() << std::endl;
    std::cout << "c[1] = " << c[1] << std::endl << std::endl;

    Array<char> d(7);
    std::cout << "Size of d[] : " << d.size() << std::endl;
    d[0] = 'k';
    std::cout << "d[0] = " << d[0] << std::endl << std::endl;

    std::cout << "Checking copies:" << std::endl;
    Array<int> bcopy(b);
    for (int i = 0; i < 10; i ++)
        std::cout << "b[" << i << "] = " << b[i] << "     b_copy[" << i << "] = " << bcopy[i] << std::endl;
    std::cout << "Changing b[0] from 1 to 42.." << std::endl;
    b[0] = 42;
    std::cout << "NOW: b[0] = " << b[0] << "     b_copy[0] = " << bcopy[0] << std::endl << std::endl;

    return (0);
}