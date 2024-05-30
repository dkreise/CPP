#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    Bureaucrat b1("first", 7);
    std::cout << b1 << std::endl;
    Bureaucrat b2("second", 100);
    std::cout << b2 << std::endl;

    Form f1("form1", 45, 100);
    std::cout << f1 << std::endl;
    Form f2("form2", 3, 5);
    std::cout << f2 << std::endl;

    f1.beSigned(b1);
    std::cout << f1 << std::endl;
    f2.beSigned(b2);
    std::cout << f2 << std::endl;

    b1.signForm(f2);
    b2.signForm(f1);

    return (0);
}