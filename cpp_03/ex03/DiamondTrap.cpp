#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void): ClapTrap(100, 100, 30)
{
	std::cout << "DiamondTrap constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name, 100, 100, 30)
{
	std::cout << "DiamondTrap constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const & src): ClapTrap(src.getName(), src.getHitP(), src.getEnergyP(), src.getDamage())
{
	std::cout << "Diamond constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap & DiamondTrap::operator=(DiamondTrap const & rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_hit_p = rhs.getHitP();
		this->_energy_p = rhs.getEnergyP();
		this->_damage = rhs.getDamage();
	}
	return (*this);
}

void DiamondTrap::attack(const std::string & target)
{
	if (this->_energy_p > 0)
	{	
		std::cout << "DiamondTrap " << this->_name << " attacks " << target;
		std::cout << ", causing " << this->_damage << " points of damage!" << std::endl;
		this->_energy_p = this->_energy_p - 1;
	}
	else
	{
		std::cout << "DiamondTrap " << this->_name << " is not able to attack! ";
		std::cout << "He does not have enough energy!" << std::endl;
	}
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap " << this->_name << " is giving you a high five!" << std::endl;
}