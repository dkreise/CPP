#include <iostream>
#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main(void)
{
    int N = 7;
    Zombie* zombies = zombieHorde(N, "zzz");

    std::cout << "First zombie: " << (*zombies).get_name() << std::endl << std::endl;

    for (int i = 0; i < N; i ++)
        std::cout << i + 1 << ": " << zombies[i].get_name() << std::endl;

    delete [] zombies;
    return (0);
}