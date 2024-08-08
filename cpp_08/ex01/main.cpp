#include "Span.hpp"

int main(void)
{
    Span sp = Span(5);
    std::cout << "Created span sp of length 5" << std::endl;

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "Numbers added to sp: 6 3 17 9 11" << std::endl;
    std::cout <<  "Shortest span for sp: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span for sp: " << sp.longestSpan() << std::endl << std::endl;

    Span sp2 = Span(7);
    std::cout << "Created span sp2 of length 7" << std::endl;
    try
    {
        std::cout << "Trying to add a range from 1 to 10:" << std::endl;
        sp2.addRange(1, 10);
        std::cout << "Numbers added to sp2: 1 2 3 4 5 6 7 8 9 10" << std::endl;
        std::cout << sp2.shortestSpan() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "ERROR: " << e.what() << std::endl;
    }
    sp2.addNumber(100);
    sp2.addRange(-2, 2);
    std::cout << "Numbers added to sp2: 100 -2 -1 0 1 2" << std::endl;
    std::cout << "Shortest span for sp2: " << sp2.shortestSpan() << std::endl;
    std::cout << "Longest span for sp2: " << sp2.longestSpan() << std::endl << std::endl;

    Span sp3 = Span(10);
    std::cout << "Created span sp3 of length 10" << std::endl;
    sp3.addRange(2, 7);
    std::cout << "Numbers added to sp3: 2 3 4 5 6 7" << std::endl;
    Span sp3_copy = Span(sp3);
    std::cout << "Created span sp3copy as a copy of span sp3" << std::endl;
    sp3_copy.addNumber(42);
    std::cout << "Number 42 added to sp3copy" << std::endl;
    sp3 = sp2;
    std::cout << "Span sp3 = sp2 now" << std::endl;
    std::cout << "Shortest span for sp3: " << sp3.shortestSpan() << std::endl;
    std::cout << "Longest span for sp3: " << sp3.longestSpan() << std::endl;
    std::cout << "Shortest span for sp3copy: " << sp3_copy.shortestSpan() << std::endl;
    std::cout << "Longest span for sp3copy: " << sp3_copy.longestSpan() << std::endl;

    return (0);
}