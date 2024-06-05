#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
    public:
        Intern(void);
        Intern(const Intern & src);
        ~Intern(void);

        Intern & operator=(const Intern & src);

        AForm* makeForm(std::string formname, std::string target) const;

    private:
        AForm* _makeShrubberyForm(std::string target) const;
        AForm* _makeRobotomyForm(std::string target) const;
        AForm* _makePresidentialForm(std::string target) const;
};

#endif