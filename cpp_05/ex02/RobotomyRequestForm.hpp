#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    public:
        RobotomyRequestForm(void);
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(const RobotomyRequestForm & src);
        ~RobotomyRequestForm(void);

        std::string getTarget(void) const;
    
    private:
        std::string _target;
        virtual void executeForm(void) const;
};

#endif