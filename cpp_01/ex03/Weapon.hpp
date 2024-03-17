#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon
{
    public:
        Weapon(void);
        Weapon(std::string new_type);
        ~Weapon(void);
        std::string& getType(void); // const..
        void setType(std::string new_type);
    private:
        std::string type;
};

#endif