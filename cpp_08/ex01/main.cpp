#include "Span.hpp"

int main(void)
{
    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    Span sp2 = Span(7);
    try
    {
        sp2.addRange(1, 10);
        std::cout << sp2.shortestSpan() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    sp2.addNumber(100);
    sp2.addRange(1, 5);
    std::cout << sp2.shortestSpan() << std::endl;
    std::cout << sp2.longestSpan() << std::endl;

    Span sp3 = Span(10);
    sp3.addRange(2, 7);
    Span sp3_copy = Span(sp3);
    sp3_copy.addNumber(42);
    sp3 = sp2;
    std::cout << sp3.shortestSpan() << std::endl;
    std::cout << sp3.longestSpan() << std::endl;
    std::cout << sp3_copy.shortestSpan() << std::endl;
    std::cout << sp3_copy.longestSpan() << std::endl;

    return (0);
}