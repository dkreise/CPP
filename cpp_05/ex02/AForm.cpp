#include "AForm.hpp"

AForm::AForm(void) : _name("*no name*"), _is_signed(false), _grade_to_sign(LOWEST_GRADE), _grade_to_execute(LOWEST_GRADE) {}

AForm::AForm(std::string name, int grade_to_sign, int grade_to_execute) : _name(name), _is_signed(false), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute)
{
    try
    {
        if (grade_to_sign < HIGHEST_GRADE || grade_to_execute < HIGHEST_GRADE)
            throw AForm::GradeTooHighException();
        else if (grade_to_sign > LOWEST_GRADE || grade_to_execute > LOWEST_GRADE)
            throw AForm::GradeTooLowException();
    }
    catch(const AForm::GradeTooHighException& e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch(const AForm::GradeTooLowException& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

AForm::AForm(AForm const & src) : _name(src._name), _is_signed(false), _grade_to_sign(src._grade_to_sign), _grade_to_execute(src._grade_to_execute) {}

AForm::~AForm(void) {}

AForm & AForm::operator=(AForm const & src)
{
    (void) src;
    return (*this);
}

std::string AForm::getName(void) const
{
    return (this->_name);
}

bool AForm::getSignedStatus(void) const
{
    return (this->_is_signed);
}

int AForm::getGradeToSign(void) const
{
    return (this->_grade_to_sign);
}

int AForm::getGradeToExecute(void) const
{
    return (this->_grade_to_execute);
}

void AForm::beSigned(const Bureaucrat& b)
{
    try
    {
        if (b.getGrade() <= this->_grade_to_sign)
            this->_is_signed = true;
        else
            throw AForm::GradeTooLowException();
    }
    catch(const AForm::GradeTooLowException& e)
    {
        std::cerr << e.what();
        std::cerr << " Form " << this->_name << " cannot be signed by bureaucrat " << b.getName() << "." << std::endl;
    }
}

void AForm::execute(Bureaucrat const & executor) const
{
    if (this->_is_signed == false)
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->_grade_to_execute)
        throw AForm::GradeTooLowException();
    executeForm();
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return ("Error: Grade is too high.");
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return ("Error: Grade is too low.");
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return ("Error: Form is not signed.");
}

std::ostream &	operator<<(std::ostream& o, const AForm & src)
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