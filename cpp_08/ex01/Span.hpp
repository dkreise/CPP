#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <vector>
#include <climits>

class Span
{
    public:
        Span(unsigned int n);
        Span(Span const & src);
        ~Span(void);

        Span & operator=(Span const & src);

        void addNumber(int i);
        void addRange(int start, int end);
        unsigned int shortestSpan(void);
        unsigned int longestSpan(void);

    private:
        Span(void);

        unsigned int _n;
        std::vector<int> _nums;
};

#endif