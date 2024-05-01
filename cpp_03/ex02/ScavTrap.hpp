#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.hpp"

#define SCAV_HITP 100
#define SCAV_ENERGYP 50
#define SCAV_DAMAGE 20

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const & src);
		~ScavTrap(void);

		ScavTrap & operator=(ScavTrap const & rhs);

		virtual void attack(const std::string & target);
		void guardGate(void);
};

#endif