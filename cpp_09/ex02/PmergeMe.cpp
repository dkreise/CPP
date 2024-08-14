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

void PmergeMe::pmerge(char** nums)
{
    try
    {
        std::vector<int> arrV;
        std::vector<int> sortedV;
        std::deque<int> arrD;
        std::deque<int> sortedD;
        
        arrV = parseV(nums);
        arrD = parseD(arrV);
        std::cout << "Before: ";
        printVector(arrV);
        
        clock_t startv = clock();
        sortedV = mergeInsertSortVector(arrV);
        clock_t endv = clock();

        clock_t startd = clock();
        sortedD = mergeInsertSortDeque(arrD);
        clock_t endd = clock();

        std::cout << "After: ";
        printVector(sortedV);

        double elapsed = static_cast<double>(endv - startv) / CLOCKS_PER_SEC * 1000000.0;
        std::cout << "Time to process a range of " << arrV.size() << " elements with std::vector : " << elapsed << " us" << std::endl;
        elapsed = static_cast<double>(endd - startd) / CLOCKS_PER_SEC * 1000000.0;
        std::cout << "Time to process a range of " << arrD.size() << " elements with std::deque : " << elapsed << " us" << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}

std::vector<int> PmergeMe::mergeInsertSortVector(std::vector<int> arr)
{
    std::vector<int> sorted;
    int n;
    bool is_odd;
    std::vector<std::pair<int, int> > pairs;

    n = arr.size();
    if (n % 2 == 1)    
        is_odd = true;
    else 
        is_odd = false;
    pairs = getSortedPairsV(arr);
    
    sorted = getSortedVector(pairs);
    if (is_odd)
        insertBSVector(sorted, sorted.size(), arr[n - 1]);

    return (sorted);
}

std::deque<int> PmergeMe::mergeInsertSortDeque(std::deque<int> arr)
{
    std::deque<int> sorted;
    int n;
    bool is_odd;
    std::deque<std::pair<int, int> > pairs;

    n = arr.size();
    if (n % 2 == 1)    
        is_odd = true;
    else 
        is_odd = false;
    pairs = getSortedPairsD(arr);
    
    sorted = getSortedDeque(pairs);
    if (is_odd)
        insertBSDeque(sorted, sorted.size(), arr[n - 1]);

    return (sorted);
}

std::vector<int> PmergeMe::parseV(char** nums)
{
    std::vector<int> arr;
    for (int i = 1; nums[i] != NULL; i ++)
    {
        checkOnlyDigits(nums[i]);
        checkPosInt(nums[i]);
        arr.push_back(std::atoi(nums[i]));
    }
    return (arr);
}

std::deque<int> PmergeMe::parseD(std::vector<int>& nums)
{
    std::deque<int> arr;

    for (size_t i = 0; i < nums.size(); i ++)
    {
        arr.push_back(nums[i]);
    }
    return (arr);
}

void PmergeMe::checkOnlyDigits(char* num)
{
    int i = 0;

    if (num[0] == '\0')
    {
        throw std::logic_error("Error: empty string.");
    }
    if (num[0] == '-' || num[0] == '+')
    {
        i ++;
    }
    while (num[i] != '\0')
    {
        if (!std::isdigit(num[i]))
        {
            throw std::logic_error("Error: not a number.");
        }
        i ++;
    }
}

void PmergeMe::checkPosInt(char* num)
{
    float n = std::atof(num);

    if (n < 0)
        throw std::logic_error("Error: not a positive number.");
    if (n > (float)INT_MAX)
        throw std::logic_error("Error: number is too large.");
}

std::vector<std::pair<int, int> > PmergeMe::getSortedPairsV(std::vector<int>& arr)
{
    int n = arr.size();
    std::vector<std::pair<int, int> > pairs;

    for (int i = 0; i < n; i += 2)
    {
        if (i + 1 == n)
            continue;
        else if (arr[i] > arr[i + 1])
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
        else
            pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
    }
    return (sortPairsV(pairs));
}

std::deque<std::pair<int, int> > PmergeMe::getSortedPairsD(std::deque<int>& arr)
{
    int n = arr.size();
    std::deque<std::pair<int, int> > pairs;

    for (int i = 0; i < n; i += 2)
    {
        if (i + 1 == n)
            continue;
        else if (arr[i] > arr[i + 1])
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
        else
            pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
    }
    return (sortPairsD(pairs));
}

std::vector<std::pair<int, int>  > PmergeMe::sortPairsV(std::vector<std::pair<int, int> > pairs)
{
    int n = pairs.size();
    if (n <= 1)
        return (pairs);
    
    std::vector<std::pair<int, int> > left;
    std::vector<std::pair<int, int> > right;
    std::copy(pairs.begin(), pairs.begin() + n / 2, std::back_inserter(left));
    std::copy(pairs.begin() + n / 2, pairs.end(), std::back_inserter(right));

    return (mergePairsV(sortPairsV(left), sortPairsV(right)));
}

std::deque<std::pair<int, int> > PmergeMe::sortPairsD(std::deque<std::pair<int, int> > pairs)
{
    int n = pairs.size();
    if (n <= 1)
        return (pairs);
    
    std::deque<std::pair<int, int> > left;
    std::deque<std::pair<int, int> > right;
    std::copy(pairs.begin(), pairs.begin() + n / 2, std::back_inserter(left));
    std::copy(pairs.begin() + n / 2, pairs.end(), std::back_inserter(right));

    return (mergePairsD(sortPairsD(left), sortPairsD(right)));
}

std::vector<std::pair<int, int> > PmergeMe::mergePairsV(std::vector<std::pair<int, int> > left, std::vector<std::pair<int, int> > right)
{
    std::vector<std::pair<int, int> > sorted_pairs;
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

std::deque<std::pair<int, int> > PmergeMe::mergePairsD(std::deque<std::pair<int, int> > left, std::deque<std::pair<int, int> > right)
{
    std::deque<std::pair<int, int> > sorted_pairs;
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

std::vector<int> PmergeMe::getSortedVector(std::vector<std::pair<int, int> > pairs)
{
    std::vector<int> sorted;
    int n = pairs.size();

    for (int i = 0; i < n; i ++)
        sorted.push_back(pairs[i].first);

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
           insertBSVector(sorted, len, pairs[j_cur - 1].second);
        j_cur --;
        while (j_cur > i)
        {
            if (j_cur <= n)
            {
                insertBSVector(sorted, len, pairs[j_cur - 1].second);
            }
            j_cur --;
        }
        i = j_prev;
    }

    return (sorted);
}

std::deque<int> PmergeMe::getSortedDeque(std::deque<std::pair<int, int> > pairs)
{
    std::deque<int> sorted;
    int n = pairs.size();

    for (int i = 0; i < n; i ++)
        sorted.push_back(pairs[i].first);

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
           insertBSDeque(sorted, len, pairs[j_cur - 1].second);
        j_cur --;
        while (j_cur > i)
        {
            if (j_cur <= n)
            {
                insertBSDeque(sorted, len, pairs[j_cur - 1].second);
            }
            j_cur --;
        }
        i = j_prev;
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

void PmergeMe::insertBSVector(std::vector<int>& sorted, int len, int val)
{
    int n = sorted.size();
    if (n == 0)
    {
        sorted.push_back(val);
        return;
    }

    if (len > n)
        len = n;
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

void PmergeMe::insertBSDeque(std::deque<int>& sorted, int len, int val)
{
    int n = sorted.size();
    if (n == 0)
    {
        sorted.push_back(val);
        return;
    }

    if (len > n)
        len = n;
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

void PmergeMe::printDeque(std::deque<int> d)
{
    int n = d.size();

    std::cout << "[ ";
    for (int i = 0; i < n; i ++)
    {
        std::cout << d[i];
        if (i != n - 1)
            std::cout << ", ";
    }
    std::cout << " ]" << std::endl;
}

void PmergeMe::printPairsV(std::vector<std::pair<int, int> > p)
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

void PmergeMe::checkSorted(std::vector<int>& arr)
{
    for (size_t i = 1; i < arr.size(); i ++)
    {
        if (arr[i - 1] > arr[i])
        {
            std::cout << "NOT SORTED" << std::endl;
            return;
        }
    }
    std::cout << "SORTED GOOD" << std::endl;
}