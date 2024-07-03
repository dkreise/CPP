#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
    if (argc < 2)
        return (0); //print err
    
    std::vector<int> ar = PmergeMe::pmerge(argv);
    return (0);
}