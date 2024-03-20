#include <iostream>
#include "Harl.hpp"

Harl::Harl(void) {}

Harl::~Harl(void) {}

void Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You did not put \
enough bacon in my burger! If you did, I would not be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I have been coming for \
years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

// int Harl::convert(std::string level)
// {
// 	int l;

// 	if (level == "DEBUG")
// 		return (1);
// 	else if (level == "INFO")
// }

void Harl::complain(std::string level)
{
	int l;

	l = level[0];
	switch (l)
	{
		case 'D':
			std::cout << "debugggg" << std::endl;
			break;
		case 'I':
			info();
			std::cout << "infoooo" << std::endl;
			break;
		case 'W':
			std::cout << "warningggg" << std::endl;
			break;
		case 'E':
			std::cout << "errorrrr" << std::endl;
			break;
		default:
			std::cout << "invalid level" << std::endl;
	}
}