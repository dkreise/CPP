#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

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
    std::cout << "------- CREATING AN INTERN -------" << std::endl;
    Intern someIntern;

    std::cout << std::endl << "------- CREATING THREE FORMS BY INTERN -------" << std::endl;
    AForm* f1;
    AForm* f2;
    AForm* f3;
    f1 = someIntern.makeForm("shrubbery creation", "someTarget1");
    f2 = someIntern.makeForm("robotomy request", "someTarget2");
    f3 = someIntern.makeForm("Presidential Pardon", "someTarget3");
    if (f1)
        std::cout << *f1 << std::endl;
    if (f2)
        std::cout << *f2 << std::endl;
    if (f3)
        std::cout << *f3 << std::endl;

    Bureaucrat b1 = test_bureaucrat_ctor("First", 3);
    b1.signForm(*f1);
    b1.executeForm(*f1);

    delete f1;
    delete f2;
    delete f3;

    std::cout << std::endl << "------- TRYING TO CREATE UNEXISTING FORM -------" << std::endl;
    AForm* f;
    f = someIntern.makeForm("unexisting form", "target");
    if (f)
        std::cout << *f << std::endl;
    delete f;  

    return (0);
}