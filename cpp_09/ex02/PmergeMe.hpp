#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <iostream>
#include <stdexcept>
#include <cmath>
#include <vector>

class PmergeMe
{
    public:
        static std::vector<int> pmerge(char** nums);

    private:
        PmergeMe(void);
        PmergeMe(PmergeMe const & src);
        ~PmergeMe(void);
        PmergeMe & operator=(PmergeMe const & src);

        // help functions:
        static std::vector<int> parse(char** nums);

        static std::vector<std::pair<int, int>> getSortedPairs(std::vector<int>& arr);
        static std::vector<std::pair<int, int>> sortPairs(std::vector<std::pair<int, int>> pairs);
        static std::vector<std::pair<int, int>> mergePairs(std::vector<std::pair<int, int>> left, std::vector<std::pair<int, int>> right);

        static void printVector(std::vector<int> v);
        static void printPairs(std::vector<std::pair<int, int>> p);

        static std::vector<int> getSortedVector(std::vector<std::pair<int, int>> pairs);
        static int nextJacobsthal(int& prev, int& prevprev);
        static int nextLength(int len, int& pow);
        static void insertBS(std::vector<int>& sorted, int len, int val);
};

#endif