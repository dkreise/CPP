#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>

#define CLAP_HITP 10
#define CLAP_ENERGYP 10
#define CLAP_DAMAGE 0

class ClapTrap
{
	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const & src);
		~ClapTrap(void);

		ClapTrap & operator=(ClapTrap const & rhs);

		std::string getName(void) const;
		unsigned int getHitP(void) const;
		unsigned int getEnergyP(void) const;
		unsigned int getDamage(void) const;
		void attack(const std::string & target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

	private:
		std::string _name;
		unsigned int _hit_p;
		unsigned int _energy_p;
		unsigned int _damage;
};

#endif