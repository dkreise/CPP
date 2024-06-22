#include "Span.hpp"

Span::Span(void) {}

Span::Span(unsigned int n) : _n(n) {}

//copy ctor

Span::~Span(void) {}

// =

void Span::addNumber(int i)
{
    if (this->_nums.size() >= this->_n)
        throw std::logic_error("Impossible to add more numbers."); // search appropriate excp
    this->_nums.push_back(i);
}

void Span::addRange(int start, int end)
{
    unsigned int range = std::abs(start - end) + 1;
    unsigned int size = this->_nums.size();

    if (start > end)
        throw std::logic_error("Ivalid range.");
    if (this->_n - size < range)
        throw std::logic_error("Range is too long.");
    
    for (int i = start; i <= end; i ++) // search for some function!!
        this->_nums.push_back(i); 
}

unsigned int Span::shortestSpan(void) const
{
    unsigned int size = this->_nums.size();
    unsigned int cur = 0;
    unsigned int shortest = INT_MAX;

    if (this->_nums.size() <= 1)
        throw std::logic_error("Not enough numbers for finding the span.");
    std::sort(this->_nums.begin(), this->_nums.end());
    for (int i = 1; i < size; i ++)
    {
        cur = std::abs(this->_nums[i] - this->_nums[i]);
        shortest = std::min(shortest, cur);
    }
    return (shortest);
}

unsigned int Span::longestSpan(void) const
{
    unsigned int size = this->_nums.size();

    if (this->_nums.size() <= 1)
        throw std::logic_error("Not enough numbers for finding the span.");
    std::sort(this->_nums.begin(), this->_nums.end());
    return (abs(this->_nums[0] - abs(this->_nums[size - 1])));
}