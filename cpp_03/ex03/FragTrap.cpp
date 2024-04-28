#include "FragTrap.hpp"

FragTrap::FragTrap(void): ClapTrap(FRAG_HITP, FRAG_ENERGYP, FRAG_DAMAGE)
{
	std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name, FRAG_HITP, FRAG_ENERGYP, FRAG_DAMAGE)
{
	std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(FragTrap const & src): ClapTrap(src.getName(), src.getHitP(), src.getEnergyP(), src.getDamage())
{
	std::cout << "FragTrap constructor called" << std::endl;
}

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

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->_name << " is giving you a high five!" << std::endl;
}