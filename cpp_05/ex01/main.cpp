#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat test_bureaucrat_ctor(std::string name, int grade)
{
    Bureaucrat b(name, LOWEST_GRADE); // why is not working without this ??
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

Form test_form_ctor(std::string name, int grade_to_sign, int grade_to_execute)
{
    Form f(name, LOWEST_GRADE, LOWEST_GRADE);
    try
    {
        Form f(name, grade_to_sign, grade_to_execute);
        return (f);
    }
    catch(const Form::GradeTooHighException& e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch(const Form::GradeTooLowException& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (f);
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

void test_beSigned(Form & f, const Bureaucrat& b)
{
    std::cout << "For form " << f.getName() << ":" << std::endl;
    try
    {
        f.beSigned(b);
    }
    catch(const Form::GradeTooLowException& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

int main(void)
{
    std::cout << "------- CREATING TWO BUREAUCRATS -------" << std::endl;
    Bureaucrat b1 = test_bureaucrat_ctor("first", 7);
    std::cout << b1 << std::endl;
    Bureaucrat b2 = test_bureaucrat_ctor("second", 100);
    std::cout << b2 << std::endl;

    std::cout << std::endl << "------- CREATING TWO FORMS -------" << std::endl;
    Form f1 = test_form_ctor("form1", 45, 100);
    std::cout << f1 << std::endl;
    Form f2 = test_form_ctor("form2", 3, 5);
    std::cout << f2 << std::endl;

    std::cout << std::endl << "------- EXCEPTION CATCH IN CONSTRUCTOR -------" << std::endl;
    Form f3 = test_form_ctor("form3", 333, 0);
    std::cout << f3 << std::endl;

    std::cout << std::endl << "------- BE_SIGNED TEST -------" << std::endl;
    //f1.beSigned(b1);
    test_beSigned(f1, b1);
    std::cout << f1 << std::endl;
    //f2.beSigned(b2);
    test_beSigned(f2, b2);
    std::cout << f2 << std::endl;

    std::cout << std::endl << "------- SIGN_FORM TEST -------" << std::endl;
    b1.signForm(f2);
    b2.signForm(f1);
    b1.signForm(f3);

    return (0);
}