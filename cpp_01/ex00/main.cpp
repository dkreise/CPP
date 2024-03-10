#include <iostream>
#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main(void)
{
    Zombie z1("zombie_constructor");
    z1.announce();

    Zombie* z2 = newZombie("zombie_function");  
    z2->announce();

    randomChump("zombie_random");

    delete z2;
    return (0);
}