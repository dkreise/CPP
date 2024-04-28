#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void): ClapTrap(SCAV_HITP, SCAV_ENERGYP, SCAV_DAMAGE)
{
	this->_damage = 3;
	std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name, SCAV_HITP, SCAV_ENERGYP, SCAV_DAMAGE)
{
	std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & src): ClapTrap(src.getName(), src.getHitP(), src.getEnergyP(), src.getDamage())
{
	std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & rhs)
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

void ScavTrap::attack(const std::string & target)
{
	if (this->_energy_p > 0)
	{	
		std::cout << "ScavTrap " << this->_name << " attacks " << target;
		std::cout << ", causing " << this->_damage << " points of damage!" << std::endl;
		this->_energy_p = this->_energy_p - 1;
	}
	else
	{
		std::cout << "ScavTrap " << this->_name << " is not able to attack! ";
		std::cout << "He does not have enough energy!" << std::endl;
	}
}

void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode!" << std::endl;
}