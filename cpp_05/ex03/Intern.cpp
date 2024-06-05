#include "Intern.hpp"

Intern::Intern(void) {}

Intern::Intern(const Intern & src) 
{
    (void) src;
}

Intern::~Intern(void) {}

Intern & Intern::operator=(const Intern & src)
{
    (void) src;
    return (*this);
}

AForm* Intern::_makeShrubberyForm(std::string target) const
{
    return (new ShrubberyCreationForm(target));
}

AForm* Intern::_makeRobotomyForm(std::string target) const
{
    return (new RobotomyRequestForm(target));
}

AForm* Intern::_makePresidentialForm(std::string target) const
{
    return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(std::string formname, std::string target) const
{
    AForm* (Intern::*functions[3])(std::string) const;
    functions[0] = &Intern::_makeShrubberyForm;
    functions[1] = &Intern::_makeRobotomyForm;
    functions[2] = &Intern::_makePresidentialForm;

    std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

    for (int i = 0; formname[i] != '\0'; i ++)
        formname[i] = std::tolower(formname[i]);

    for (int i = 0; i < 3; i ++)
    {
        if (formname == forms[i])
        {
            std::cout << "Intern creates " << formname << " form." << std::endl;
            return ((this->*functions[i])(target));
        }
    }
    std::cout << "Form does not exist. Available forms: " << forms[0] << ", " << forms[1] << ", " << forms[2] << "." << std::endl;
    return (NULL);
}