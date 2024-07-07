#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("*no name*"), _grade(LOWEST_GRADE) {}

Bureaucrat::Bureaucrat(std::string name) : _name(name), _grade(LOWEST_GRADE) {}

Bureaucrat::Bureaucrat(int grade) : _name("*no name*")
{
    this->_grade = grade;
    if (grade < HIGHEST_GRADE)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > LOWEST_GRADE)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
    this->_grade = grade;
    if (grade < HIGHEST_GRADE)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > LOWEST_GRADE)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat & src) : _name(src._name), _grade(src._grade) {}

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat & Bureaucrat::operator=(const Bureaucrat & src)
{
    this->_grade = src._grade;
    return (*this);
}

std::string Bureaucrat::getName(void) const
{
    return (this->_name);
}

int Bureaucrat::getGrade(void) const
{
    return (this->_grade);
}

void Bureaucrat::incrementGrade(void)
{
    if (this->_grade - 1 < HIGHEST_GRADE)
        throw Bureaucrat::GradeTooHighException();
    this->_grade --;
}

void Bureaucrat::decrementGrade(void)
{
    if (this->_grade + 1 > LOWEST_GRADE)
        throw Bureaucrat::GradeTooLowException();
    this->_grade ++;
}

void Bureaucrat::signForm(Form& f) const
{
    try
    {
        if (f.getSignedStatus() == true)
            std::cout << "Bureaucrat " << this->_name << " could not sign form " << f.getName() << " because it was already signed." << std::endl;
        else
        {
            f.beSigned(*this);
            if (f.getSignedStatus() == true)
                std::cout << "Bureaucrat " << this->_name << " signed form " << f.getName() << "." << std::endl;
        }
    }
    catch(const Form::GradeTooLowException& e)
    {
        std::cout << "Bureaucrat " << this->_name << " could not sign form " << f.getName() << " because of too low grade." << std::endl;
    }
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Error: Grade is too high.");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Error: Grade is too low.");
}

std::ostream &	operator<<(std::ostream& o, const Bureaucrat & src)
{
	o << src.getName() << ", bureaucrat grade " << src.getGrade();
	return (o);
}