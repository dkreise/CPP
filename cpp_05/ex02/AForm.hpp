#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    public:
        AForm(void);
        AForm(std::string name);
        AForm(std::string name, int grade_to_sign, int grade_to_execute);
        AForm(const AForm & src);
        ~AForm(void);

        AForm & operator=(const AForm & src);

        std::string getName(void) const;
        bool getSignedStatus(void) const;
        int getGradeToSign(void) const;
        int getGradeToExecute(void) const;

        void beSigned(const Bureaucrat& b);
        void execute(Bureaucrat const & executor) const;

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
        class FormNotSignedException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
    
    protected:
        virtual void executeForm(void) const = 0;

    private:
        const std::string _name;
        bool _is_signed;
        const int _grade_to_sign;
        const int _grade_to_execute;
};

std::ostream & operator<<(std::ostream & o, const AForm & src);

#endif