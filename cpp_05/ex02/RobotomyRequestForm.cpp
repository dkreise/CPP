#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45), _target("*no target*") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & src) : AForm("RobotomyRequestForm", 72, 45), _target(src._target) {}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

std::string RobotomyRequestForm::getTarget(void) const
{
    return (this->_target);
}

void RobotomyRequestForm::executeForm(void) const
{
    std::cout << "* drilling noises *" << std::endl;
    
    int random = std::rand();
    if (random % 2 == 0)
        std::cout << this->_target << " has been robotomized successfully!!" << std::endl;
    else
        std::cout << "Robotomy of " << this->_target << " failed.." << std::endl;
}