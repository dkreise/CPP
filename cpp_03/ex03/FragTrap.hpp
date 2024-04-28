#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include "ClapTrap.hpp"

#define FRAG_HITP 100
#define FRAG_ENERGYP 100
#define FRAG_DAMAGE 30

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(FragTrap const & src);
		virtual ~FragTrap(void);

		FragTrap & operator=(FragTrap const & rhs);

		void highFivesGuys(void);
};

#endif