#include "FragTrap.hpp"

FragTrap::FragTrap(void): ClapTrap(100, 100, 30)
{
	std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name, 100, 100, 30)
{
	std::cout << "FragTrap constructor called" << std::endl;
}

// FragTrap::FragTrap(FragTrap const & src): _name(src.getName()), _hit_p(src.getHitP()), _energy_p(src.getEnergyP()), _damage(src.getDamage())
// {
// 	std::cout << "FragTrap copy constructor called" << std::endl;
// }

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap & FragTrap::operator=(FragTrap const & rhs)
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

void FragTrap::attack(const std::string & target)
{
	if (this->_energy_p > 0)
	{	
		std::cout << "FragTrap " << this->_name << " attacks " << target;
		std::cout << ", causing " << this->_damage << " points of damage!" << std::endl;
		this->_energy_p = this->_energy_p - 1;
	}
	else
	{
		std::cout << "FragTrap " << this->_name << " is not able to attack! ";
		std::cout << "He does not have enough energy!" << std::endl;
	}
}

void FragTrap::highFiveGuys(void)
{
	std::cout << "FragTrap " << this->_name << " is giving you a high five!" << std::endl;
}