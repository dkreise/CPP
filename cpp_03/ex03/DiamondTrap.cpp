#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void): ClapTrap(), ScavTrap(), FragTrap()
{
	std::cout << "DiamondTrap constructor called" << std::endl;
	this->_hit_p = FragTrap::_hit_p;
	this->_energy_p = ScavTrap::_energy_p;
	this->_damage = FragTrap::_damage;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	std::cout << "DiamondTrap constructor called" << std::endl;
	this->_name = name;
	this->_hit_p = FragTrap::_hit_p;
	this->_energy_p = ScavTrap::_energy_p;
	this->_damage = FragTrap::_damage;
}

DiamondTrap::DiamondTrap(DiamondTrap const & src): ClapTrap(src.getName() + "_clap_name"), ScavTrap(src.getName()), FragTrap(src.getName())
{
	std::cout << "Diamond constructor called" << std::endl;
	*this = src;
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
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "Name of DiamondTrap: " << this->_name << std::endl;
	std::cout << "Name of its ClapTrap: " << this->ClapTrap::_name << std::endl;
}