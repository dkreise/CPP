#include "Bureaucrat.hpp"

int main(void)
{
    Bureaucrat b1("first");
    std::cout << b1 << std::endl;
    Bureaucrat b2(24);
    std::cout << b2 << std::endl;
    Bureaucrat b3("third", 7);
    std::cout << b3 << std::endl;

    Bureaucrat b4("fourth", 333);
    std::cout << b4 << std::endl;
    
    b1.decrementGrade();
    std::cout << b1 << std::endl;
    b1.incrementGrade();
    std::cout << b1 << std::endl;
    b3.decrementGrade();
    b3.decrementGrade();
    std::cout << b3 << std::endl;

    return (0);
}