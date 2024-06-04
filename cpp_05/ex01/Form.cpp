#include "Form.hpp"

Form::Form(void) : _name("*no name*"), _is_signed(false), _grade_to_sign(LOWEST_GRADE), _grade_to_execute(LOWEST_GRADE) {}

Form::Form(std::string name, int grade_to_sign, int grade_to_execute) : _name(name), _is_signed(false), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute)
{
    if (grade_to_sign < HIGHEST_GRADE || grade_to_execute < HIGHEST_GRADE)
        throw Form::GradeTooHighException();
    else if (grade_to_sign > LOWEST_GRADE || grade_to_execute > LOWEST_GRADE)
        throw Form::GradeTooLowException();
    // try
    // {
    //     if (grade_to_sign < HIGHEST_GRADE || grade_to_execute < HIGHEST_GRADE)
    //         throw Form::GradeTooHighException();
    //     else if (grade_to_sign > LOWEST_GRADE || grade_to_execute > LOWEST_GRADE)
    //         throw Form::GradeTooLowException();
    // }
    // catch(const Form::GradeTooHighException& e)
    // {
    //     std::cerr << e.what() << std::endl;
    // }
    // catch(const Form::GradeTooLowException& e)
    // {
    //     std::cerr << e.what() << std::endl;
    // }
}

Form::Form(Form const & src) : _name(src._name), _is_signed(false), _grade_to_sign(src._grade_to_sign), _grade_to_execute(src._grade_to_execute) {}

Form::~Form(void) {}

Form & Form::operator=(Form const & src)
{
    (void) src;
    return (*this);
}

std::string Form::getName(void) const
{
    return (this->_name);
}

bool Form::getSignedStatus(void) const
{
    return (this->_is_signed);
}

int Form::getGradeToSign(void) const
{
    return (this->_grade_to_sign);
}

int Form::getGradeToExecute(void) const
{
    return (this->_grade_to_execute);
}

void Form::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() <= this->_grade_to_sign)
        this->_is_signed = true;
    else
        throw Form::GradeTooLowException();
    // try
    // {
    //     if (b.getGrade() <= this->_grade_to_sign)
    //         this->_is_signed = true;
    //     else
    //         throw Form::GradeTooLowException();
    // }
    // catch(const Form::GradeTooLowException& e)
    // {
    //     std::cerr << e.what();
    //     std::cerr << " Form " << this->_name << " cannot be signed by bureaucrat " << b.getName() << "." << std::endl;
    // }
}

const char* Form::GradeTooHighException::what() const throw()
{
    return ("Error: Grade is too high.");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("Error: Grade is too low.");
}

std::ostream &	operator<<(std::ostream& o, const Form & src)
{
	o << "FORM NAME: " << src.getName() << "; STATUS: " ;
    if (src.getSignedStatus())
        o << "is signed; ";
    else
        o << "is not signed; ";
    o << "GRADE TO SIGN: " << src.getGradeToSign() << "; ";
    o << "GRADE TO EXECUTE: " << src.getGradeToExecute() << ".";
	return (o);
}