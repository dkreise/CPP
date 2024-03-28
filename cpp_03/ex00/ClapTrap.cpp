#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void): _hit_p(10), _energy_p(10), _damage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hit_p(10), _energy_p(10), _damage(0)
{
	std::cout << "ClapTrap name constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & src): _name(src.getName()), _hit_p(src.getHitP()), _energy_p(src.getEnergyP()), _damage(src.getDamage())
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap & ClapTrap::operator=(ClapTrap const & rhs)
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

std::string ClapTrap::getName(void) const
{
	return (this->_name);
}

unsigned int ClapTrap::getHitP(void) const
{
	return (this->_hit_p);
}

unsigned int ClapTrap::getEnergyP(void) const
{
	return (this->_energy_p);
}

unsigned int ClapTrap::getDamage(void) const
{
	return (this->_damage);
}

void ClapTrap::attack(const std::string & target)
{
	if (this->_energy_p > 0)
	{	
		std::cout << "ClapTrap " << this->_name << " attacks " << target;
		std::cout << ", causing " << this->_damage << " points of damage!" << std::endl;
		this->_energy_p = this->_energy_p - 1;
	}
	else
	{
		std::cout << "ClapTrap " << this->_name << " is not able to attack!";
		std::cout << "He does not have enough energy!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hit_p != 0)
	{
		std::cout << "ClapTrap " << this->_name << " takes damage of " << amount;
		std::cout << " hit points!" << std::endl;
		if (this->_hit_p >= amount)
			this->_hit_p = this->_hit_p - amount;
		else
			this->_hit_p = 0;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << this->_name << " repairs itself by getting " << amount;
	std::cout << " hit points back!" << std::endl;
	this->_energy_p = this->_energy_p - 1;
	this->_hit_p = this->_hit_p + amount;
}



