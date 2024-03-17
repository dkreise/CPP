#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
    public:
        HumanA(std::string name, Weapon w);
        ~HumanA(void);
        Weapon& weapon;
        void attack(void);
    private:    
        std::string name;
};

#endif