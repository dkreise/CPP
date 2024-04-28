#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>

class ClapTrap
{
	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const & src);
		virtual ~ClapTrap(void);

		ClapTrap & operator=(ClapTrap const & rhs);

		std::string getName(void) const;
		unsigned int getHitP(void) const;
		unsigned int getEnergyP(void) const;
		unsigned int getDamage(void) const;
		virtual void attack(const std::string & target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

	protected:
		ClapTrap(unsigned int hit, unsigned int energy, unsigned int damage);
		ClapTrap(std::string name, unsigned int hit, unsigned int energy, unsigned int damage);
		std::string _name;
		unsigned int _hit_p;
		unsigned int _energy_p;
		unsigned int _damage;
};

#endif