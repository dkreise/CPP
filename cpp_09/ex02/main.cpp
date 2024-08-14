#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cout << "Provide a sequence of positive integers as an argument to sort them." << std::endl;
        return (0);
    }
    PmergeMe::pmerge(argv);
    return (0);
}