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

    std::vector<int> arr;
    std::vector<int> sorted;
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
    
    sorted = getSortedVector(pairs);
    if (is_odd)
        insertBS(sorted, sorted.size(), arr[n - 1]);

    std::cout << "After: ";
    printVector(sorted);

    return sorted;
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

std::vector<int> PmergeMe::getSortedVector(std::vector<std::pair<int, int>> pairs)
{
    std::vector<int> sorted;
    int n = pairs.size();

    for (int i = 0; i < n; i ++)
        sorted.push_back(pairs[i].first);
    std::cout << "Array now: ";
    printVector(sorted);

    int j_prevprev = 0;
    int j_prev = 1;
    int j_cur;
    int len = 0;
    int p = 0;
    int i = 1;

    while (i <= n)
    {
        j_cur = nextJacobsthal(j_prev, j_prevprev);
        len = nextLength(len, p);
        if (j_cur <= n)
            insertBS(sorted, len, pairs[j_cur - 1].second);
        while (i < j_cur)
        {
            if (i <= n)
                insertBS(sorted, len, pairs[i - 1].second);
            i ++;
        }
        i ++;
    }

    return (sorted);
}

int PmergeMe::nextJacobsthal(int& prev, int& prevprev)
{
    int cur = prev + 2 * prevprev;
    prevprev = prev;
    prev = cur;
    return (cur);
}

int PmergeMe::nextLength(int len, int& p)
{
    int next = len + std::pow(2, p);
    p ++;
    return (next);
}

void PmergeMe::insertBS(std::vector<int>& sorted, int len, int val)
{
    if (sorted.size() == 0)
    {
        sorted.push_back(val);
        return;
    }

    int l = 0;
    int h = len - 1;
    int mid;
    int cur;
    while (l <= h)
    {
        mid = (l + h) / 2;
        cur = sorted[mid];
        if (l == h)
        {
            if (cur < val)
                l ++;
            break;
        }
        else if (cur < val)
            l = mid + 1;
        else    
            h = mid - 1;
    }
    sorted.insert(sorted.begin() + l, val);
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