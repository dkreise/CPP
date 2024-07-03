#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {}

PmergeMe::PmergeMe(PmergeMe const & src)
{
    (void) src;
}

PmergeMe::~PmergeMe(void) {}

PmergeMe & PmergeMe::operator=(PmergeMe const & src)
{
    (void) src;
    return (*this);
}

std::vector<int> PmergeMe::pmerge(char** nums)
{
    // everything in try catch
    // receive an arr
    // pairs
    // sort pairs
    // sorted arr decl
    // sortBS

    std::vector<int> arr;
    int n;
    bool is_odd;
    std::vector<std::pair<int, int>> pairs;

    arr = parse(nums);
    std::cout << "Before: ";
    printVector(arr);
    n = arr.size();
    if (n % 2 == 1)    
        is_odd = true;
    else 
        is_odd = false;
    pairs = getSortedPairs(arr);
    std::cout << "Sorted Pairs: ";
    printPairs(pairs);

    return arr;
}

std::vector<int> PmergeMe::parse(char** nums)
{
    std::vector<int> arr;
    // parse properly later (check each string if is digigt, if is int etc)
    for (int i = 1; nums[i] != NULL; i ++)
    {
        arr.push_back(std::atoi(nums[i]));
    }
    return (arr);
}

std::vector<std::pair<int, int>> PmergeMe::getSortedPairs(std::vector<int>& arr)
{
    int n = arr.size();
    std::vector<std::pair<int, int>> pairs;

    for (int i = 0; i < n; i += 2)
    {
        if (i + 1 == n)
            continue;
        else if (arr[i] > arr[i + 1])
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
        else
            pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
    }
    std::cout << "Not Sorted Pairs: ";
    printPairs(pairs);
    return (sortPairs(pairs));
}

std::vector<std::pair<int, int>> PmergeMe::sortPairs(std::vector<std::pair<int, int>> pairs)
{
    int n = pairs.size();
    if (n <= 1)
        return (pairs);
    
    std::vector<std::pair<int, int>> left;
    std::vector<std::pair<int, int>> right;
    std::copy(pairs.begin(), pairs.begin() + n / 2, std::back_inserter(left));
    std::copy(pairs.begin() + n / 2, pairs.end(), std::back_inserter(right));

    return (mergePairs(sortPairs(left), sortPairs(right)));
}

std::vector<std::pair<int, int>> PmergeMe::mergePairs(std::vector<std::pair<int, int>> left, std::vector<std::pair<int, int>> right)
{
    std::vector<std::pair<int, int>> sorted_pairs;
    int n1 = left.size();
    int n2 = right.size();

    int i1 = 0;
    int i2 = 0;
    while (i1 < n1 || i2 < n2)
    {
        if (i1 != n1 && (i2 == n2 || (left[i1].first < right[i2].first)))
        {
            sorted_pairs.push_back(left[i1]);
            i1 ++;
        }
        else
        {
            sorted_pairs.push_back(right[i2]);
            i2 ++;
        }
    }

    return (sorted_pairs);
}

void PmergeMe::printVector(std::vector<int> v)
{
    int n = v.size();

    std::cout << "[ ";
    for (int i = 0; i < n; i ++)
    {
        std::cout << v[i];
        if (i != n - 1)
            std::cout << ", ";
    }
    std::cout << " ]" << std::endl;
}

void PmergeMe::printPairs(std::vector<std::pair<int, int>> p)
{
    int n = p.size();

    std::cout << "[ ";
    for (int i = 0; i < n; i ++)
    {
        std::cout << "(" << p[i].first << ", " << p[i].second << ")";
        if (i != n - 1)
            std::cout << ", ";
    }
    std::cout << " ]" << std::endl;
}