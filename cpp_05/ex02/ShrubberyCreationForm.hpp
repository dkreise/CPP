#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    public:
        ShrubberyCreationForm(void);
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm & src);
        virtual ~ShrubberyCreationForm(void);

        std::string getTarget(void) const;
    
    private:
        std::string _target;
        virtual void executeForm(void) const;
};

#endif