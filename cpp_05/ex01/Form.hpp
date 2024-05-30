#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    public:
        Form(void);
        Form(std::string name);
        Form(std::string name, int grade_to_sign, int grade_to_execute);
        Form(const Form & src);
        ~Form(void);

        Form & operator=(const Form & src);

        std::string getName(void) const;
        bool getSignedStatus(void) const;
        int getGradeToSign(void) const;
        int getGradeToExecute(void) const;

        void beSigned(const Bureaucrat& b);

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

    private:
        const std::string _name;
        bool _is_signed;
        const int _grade_to_sign;
        const int _grade_to_execute;
};

std::ostream & operator<<(std::ostream & o, const Form & src);

#endif