#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    public:
        PresidentialPardonForm(void);
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(const PresidentialPardonForm & src);
        virtual ~PresidentialPardonForm(void);

        std::string getTarget(void) const;
    
    private:
        std::string _target;
        virtual void executeForm(void) const;
};

#endif