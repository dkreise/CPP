#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <algorithm>
#include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack(void) : std::stack<T>() {}
        MutantStack(MutantStack const & src) : std::stack<T>(src) {}
        ~MutantStack(void) {}

        MutantStack & operator=(MutantStack const & src)
        {
            return (std::stack<T>::operatot=(src));
        }

        typedef typename std::stack<T>::container_type::iterator iterator;

        iterator begin(void)
        {
            return (this->c.begin());
        }
        iterator end(void)
        {
            return (this->c.end());
        }
};

#endif