#include "easyfind.hpp"
#include <vector>
#include <list>

int main(void)
{   
    std::vector<int> v(7, 3);
    v[0] = 1;
    v[4] = 42;
    v[5] = 17;

    std::cout << std::endl << "For array:" << std::endl;
    try
    {
        std::vector<int>::iterator it = easyfind(v, 3);
        std::cout << "index of val 3: " << std::distance(v.begin(), it) << std::endl;
        it = easyfind(v, 42);
        std::cout << "index of val 42: " << std::distance(v.begin(), it) << std::endl;
        it = easyfind(v, 33);
        std::cout << "index of val 33: " << std::distance(v.begin(), it) << std::endl << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "ERROR: " << e.what() << std::endl << std::endl;
    }
    
    std::list<int> lst;
    lst.push_back(7);
    lst.push_back(42);
    lst.push_back(7);
    lst.push_back(3);

    std::cout << "For list:" << std::endl;
    try
    {
        std::list<int>::iterator it = easyfind(lst, 7);
        std::cout << "index of val 7: " << std::distance(lst.begin(), it) << std::endl;
        it = easyfind(lst, 420);
        std::cout << "index of val 420: " << std::distance(lst.begin(), it) << std::endl;
        it = easyfind(lst, 42);
        std::cout << "index of val 42: " << std::distance(lst.begin(), it) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "ERROR: " << e.what() << std::endl;
    }
}