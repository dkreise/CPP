#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("*no name*"), _grade(LOWEST_GRADE) {}

Bureaucrat::Bureaucrat(std::string name) : _name(name), _grade(LOWEST_GRADE) {}

Bureaucrat::Bureaucrat(int grade) : _name("*no name*")
{
    try
    {
        if (grade < HIGHEST_GRADE)
            throw Bureaucrat::GradeTooHighException();
        else if (grade > LOWEST_GRADE)
            throw Bureaucrat::GradeTooLowException();
        this->_grade = grade;
    }
    catch(const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << e.what();
        std::cerr << " Grade for bureaucrat " << this->_name << " was set to " << LOWEST_GRADE << " - the lowest possible." << std::endl;
        this->_grade = LOWEST_GRADE;
    }
    catch(const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << e.what();
        std::cerr << " Grade for bureaucrat " << this->_name << " was set to " << LOWEST_GRADE << " - the lowest possible." << std::endl;
        this->_grade = LOWEST_GRADE;
    }    
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
    try
    {
        if (grade < HIGHEST_GRADE)
            throw Bureaucrat::GradeTooHighException();
        else if (grade > LOWEST_GRADE)
            throw Bureaucrat::GradeTooLowException();
        this->_grade = grade;
    }
    catch(const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << e.what();
        std::cerr << " Grade for bureaucrat " << this->_name << " was set to " << LOWEST_GRADE << " - the lowest possible." << std::endl;
        this->_grade = LOWEST_GRADE;
    }
    catch(const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << e.what();
        std::cerr << " Grade for bureaucrat " << this->_name << " was set to " << LOWEST_GRADE << " - the lowest possible." << std::endl;
        this->_grade = LOWEST_GRADE;
    }
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
    try
    {
        if (this->_grade == HIGHEST_GRADE)
            throw Bureaucrat::GradeTooHighException();
        this->_grade --;
    }
    catch(const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << e.what();
        std::cerr << " Incrementing for bureaucrat " << this->_name << " is impossible." << std::endl;
    }
}

void Bureaucrat::decrementGrade(void)
{
    try
    {
        if (this->_grade == LOWEST_GRADE)
            throw Bureaucrat::GradeTooLowException();
        this->_grade ++;
    }
    catch(const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << e.what();
        std::cerr << " Decrementing for bureaucrat " << this->_name << " is impossible." << std::endl;
    }
}

std::ostream &	operator<<(std::ostream& o, const Bureaucrat & src)
{
	o << src.getName() << ", bureaucrat grade " << src.getGrade();
	return (o);
}