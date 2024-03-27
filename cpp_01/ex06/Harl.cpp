#include <iostream>
#include "Harl.hpp"

Harl::Harl(void) {}

Harl::~Harl(void) {}

void Harl::_debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::_info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You did not put \
enough bacon in my burger! If you did, I would not be asking for more!" << std::endl;
}

void Harl::_warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I have been coming for \
years whereas you started working here since last month." << std::endl;
}

void Harl::_error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
    int n = 4;
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; level[i] != '\0'; i ++)
		level[i] = std::toupper(level[i]);
	for (int i = 0; i < 4; i ++)
	{
		if (level == levels[i])
        {
            n = i;
            break ;
        }
	}
    switch (n)
    {
        case 0:
            this->_debug();
            this->_info();
            this->_warning();
            this->_error();
            break;
        case 1:
            this->_info();
            this->_warning();
            this->_error();
            break;
        case 2:
            this->_warning();
            this->_error();
            break;
        case 3:
            this->_error();
            break;
        default:
            std::cout << "The level does not exist." << std::endl;
            break;
    }
}