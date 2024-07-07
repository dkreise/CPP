#include "Bureaucrat.hpp"

Bureaucrat test_namegrade_ctor(std::string name, int grade)
{
    Bureaucrat b(name, LOWEST_GRADE);
    try
    {
        Bureaucrat b(name, grade);
        return (b);
    }
    catch(const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch(const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (b);
}

Bureaucrat test_grade_ctor(int grade)
{
    Bureaucrat b(LOWEST_GRADE);
    try
    {
        Bureaucrat b(grade);
        return (b);
    }
    catch(const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch(const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (b);
}

void test_decrement(Bureaucrat & b)
{
    std::cout << "For bureaucrat " << b.getName() << ":" << std::endl;
    try
    {
        b.decrementGrade();
        std::cout << b << std::endl;
    }
    catch(const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << e.what() << std::endl;
    }   
}

void test_increment(Bureaucrat & b)
{
    std::cout << "For bureaucrat " << b.getName() << ":" << std::endl;
    try
    {
        b.incrementGrade();
        std::cout << b << std::endl;
    }
    catch(const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << e.what() << std::endl;
    }   
}

int main(void)
{
    std::cout << "------- DEFAULT CONSTRUCTOR -------" << std::endl;
    Bureaucrat b0;
    std::cout << b0 << std::endl;

    std::cout << std::endl << "------- NAME CONSTRUCTOR -------" << std::endl;
    Bureaucrat b1("first");
    std::cout << b1 << std::endl;

    std::cout << std::endl << "------- GRADE CONSTRUCTOR -------" << std::endl;
    Bureaucrat b2 = test_grade_ctor(24);
    std::cout << b2 << std::endl;

    std::cout << std::endl << "------- NAME+GRADE CONSTRUCTOR -------" << std::endl;
    Bureaucrat b3 = test_namegrade_ctor("third", 7);
    std::cout << b3 << std::endl;

    std::cout << std::endl << "------- EXCEPTION CATCH IN CONSTRUCTOR -------" << std::endl;
    Bureaucrat b4 = test_namegrade_ctor("fourth", 333);
    std::cout << b4 << std::endl;
    
    std::cout << std::endl << "------- DECREMENT MEMBER FUNCTION -------" << std::endl;
    test_decrement(b1);
    test_decrement(b2);

    std::cout << std::endl << "------- INCREMENT MEMBER FUNCTION -------" << std::endl;
    test_increment(b3);
    Bureaucrat b5 = test_namegrade_ctor("fifth", 1);
    test_increment(b5);
    std::cout << b5 << std::endl;

    std::cout << std::endl << "------- GET MEMBER FUNCTIONS -------" << std::endl;
    std::cout << "getName() for b5: " << b5.getName() << std::endl;
    std::cout << "getGrade() for b3: " << b3.getGrade() << std::endl;

    return (0);
}