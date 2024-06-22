#include "easyfind.hpp"
#include <vector>
#include <list>

int main(void)
{   
    std::vector<int> v(7, 3);
    v[0] = 1;
    v[4] = 42;
    v[5] = 17;

    try
    {
        std::vector<int>::iterator it = easyfind(v, 3);
        std::cout << std::distance(v.begin(), it) << std::endl;
        it = easyfind(v, 42);
        std::cout << std::distance(v.begin(), it) << std::endl;
        it = easyfind(v, 33);
        std::cout << std::distance(v.begin(), it) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    // std::vector<std::string> vs;
    // vs.push_back("hello");
    // vs.push_back("world");

    // try
    // {
    //     std::vector<std::string>::iterator it = easyfind(vs, 3);
    //     std::cout << std::distance(vs.begin(), it) << std::endl;
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << std::endl;
    // }
    
    std::list<int> lst;
    lst.push_back(7);
    lst.push_back(42);
    lst.push_back(7);
    lst.push_back(3);

    try
    {
        std::list<int>::iterator it = easyfind(lst, 7);
        std::cout << std::distance(lst.begin(), it) << std::endl;
        it = easyfind(lst, 420);
        std::cout << std::distance(lst.begin(), it) << std::endl;
        it = easyfind(lst, 42);
        std::cout << std::distance(lst.begin(), it) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}