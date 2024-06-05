#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Bureaucrat test_bureaucrat_ctor(std::string name, int grade)
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

void test_beSigned(AForm & f, const Bureaucrat& b)
{
    std::cout << "For form " << f.getName() << ":" << std::endl;
    try
    {
        f.beSigned(b);
    }
    catch(const AForm::GradeTooLowException& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void test_execute(AForm & f, Bureaucrat const & b)
{
    try
    {
        f.execute(b);
    }
    catch(const AForm::FormNotSignedException& e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch(const AForm::GradeTooLowException& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
}

int main(void)
{
    std::cout << "------- CREATING THREE BUREAUCRATS -------" << std::endl;
    Bureaucrat b1 = test_bureaucrat_ctor("First", 3);
    std::cout << b1 << std::endl;
    Bureaucrat b2 = test_bureaucrat_ctor("Second", 100);
    std::cout << b2 << std::endl;
    Bureaucrat b3 = test_bureaucrat_ctor("Third", 42);
    std::cout << b3 << std::endl;

    std::cout << std::endl << "------- CREATING THREE FORMS -------" << std::endl;
    ShrubberyCreationForm f1("target1");
    std::cout << f1 << std::endl;
    RobotomyRequestForm f2("target2");
    std::cout << f2 << std::endl;
    PresidentialPardonForm f3("target3");
    std::cout << f3 << std::endl;

    std::cout << std::endl << "------- EXCEPTIONS IN EXECUTE() -------" << std::endl;
    test_execute(f1, b1);
    test_beSigned(f2, b1);
    test_execute(f2, b2);

    std::cout << std::endl << "------- SIGNING ALL FORMS -------" << std::endl;
    b1.signForm(f1);
    b1.signForm(f2);
    b1.signForm(f3);
    std::cout << f1 << std::endl << f2 << std::endl << f3 << std::endl;

    std::cout << std::endl << "------- executing -------" << std::endl;
    b2.executeForm(f1);
    b3.executeForm(f2);
    test_execute(f3, b1);

    return (0);
}