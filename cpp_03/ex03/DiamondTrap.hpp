#ifndef DIAMONDTRAP_H
#define DIAMONDTRAP_H

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	public:
		DiamondTrap(void);
		DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap const & src);
		~DiamondTrap(void);

		DiamondTrap & operator=(DiamondTrap const & rhs);

		std::string getDiamondName(void) const;
		void whoAmI(void);

	private:
		std::string _name;
};

#endif