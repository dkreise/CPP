#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void): ClapTrap(), ScavTrap(), FragTrap()
{
	std::cout << "DiamondTrap constructor called" << std::endl;
	//std::cout << "sadasdsadasdasdsad-----------------" << this->_hit_p << std::endl;
	this->_hit_p = FRAG_HITP;
	this->_energy_p = SCAV_ENERGYP;
	this->_damage = FRAG_DAMAGE;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	std::cout << "DiamondTrap constructor called" << std::endl;
	this->_name = name;
	this->_hit_p = FRAG_HITP;
	//std::cout << "sadasdsadasdasdsad-----------------" << this->_hit_p << std::endl;
	this->_energy_p = SCAV_ENERGYP;
	this->_damage = FRAG_DAMAGE;
}

DiamondTrap::DiamondTrap(DiamondTrap const & src): ClapTrap(src.getName() + "_clap_name"), ScavTrap(src.getName()), FragTrap(src.getName())
{
	std::cout << "DiamondTrap constructor called" << std::endl;
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

void DiamondTrap::whoAmI(void)
{
	std::cout << "Name of DiamondTrap: " << this->_name << std::endl;
	std::cout << "Name of its ClapTrap: " << this->ClapTrap::_name << std::endl;
}