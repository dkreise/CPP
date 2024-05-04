#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void): ClapTrap(), ScavTrap(), FragTrap()
{
	std::cout << "DiamondTrap constructor called" << std::endl;
	this->_hit_p = FRAG_HITP;
	this->_energy_p = SCAV_ENERGYP;
	this->_damage = FRAG_DAMAGE;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	std::cout << "DiamondTrap constructor called" << std::endl;
	this->_name = name;
	this->_hit_p = FRAG_HITP;
	this->_energy_p = SCAV_ENERGYP;
	this->_damage = FRAG_DAMAGE;
}

DiamondTrap::DiamondTrap(DiamondTrap const & src): ClapTrap(src.getName()), ScavTrap(src.getDiamondName()), FragTrap(src.getDiamondName())
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	this->_name = src.getDiamondName();
	this->_hit_p = src.getHitP();
	this->_energy_p = src.getEnergyP();
	this->_damage = src.getDamage();
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

std::string DiamondTrap::getDiamondName(void) const
{
	return (this->_name);
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "Name of DiamondTrap: " << this->_name << std::endl;
	std::cout << "Name of its ClapTrap: " << this->ClapTrap::_name << std::endl;
}