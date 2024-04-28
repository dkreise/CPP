#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.hpp"

#define SCAV_HITP 100
#define SCAV_ENERGYP 50
#define SCAV_DAMAGE 20

class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const & src);
		virtual ~ScavTrap(void);

		ScavTrap & operator=(ScavTrap const & rhs);

		void attack(const std::string & target);
		void guardGate(void);
};

#endif