#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <iostream>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <deque>
#include <ctime>
#include <cstdlib>

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
        static std::vector<int> mergeInsertSortVector(std::vector<int> arr);
        static std::deque<int> mergeInsertSortDeque(std::deque<int> arr);
        static std::vector<int> parseV(char** nums);
        static std::deque<int> parseD(char** nums); // change, just copy from vector

        static std::vector<std::pair<int, int> > getSortedPairsV(std::vector<int>& arr);
        static std::deque<std::pair<int, int> > getSortedPairsD(std::deque<int>& arr);
        static std::vector<std::pair<int, int> > sortPairsV(std::vector<std::pair<int, int> > pairs);
        static std::deque<std::pair<int, int> > sortPairsD(std::deque<std::pair<int, int> > pairs);
        static std::vector<std::pair<int, int> > mergePairsV(std::vector<std::pair<int, int> > left, std::vector<std::pair<int, int> > right);
        static std::deque<std::pair<int, int> > mergePairsD(std::deque<std::pair<int, int> > left, std::deque<std::pair<int, int> > right);

        static void printVector(std::vector<int> v);
        static void printDeque(std::deque<int> d);
        static void printPairsV(std::vector<std::pair<int, int> > p);
        //static void printPairsD(std::deque<std::pair<int, int> > p);

        static std::vector<int> getSortedVector(std::vector<std::pair<int, int> > pairs);
        static std::deque<int> getSortedDeque(std::deque<std::pair<int, int> > pairs);
        static int nextJacobsthal(int& prev, int& prevprev);
        static int nextLength(int len, int& pow);
        static void insertBSVector(std::vector<int>& sorted, int len, int val);
        static void insertBSDeque(std::deque<int>& sorted, int len, int val);
};

#endif