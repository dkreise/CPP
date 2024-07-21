#include "MutantStack.hpp"
#include <list>

int main(void)
{
    std::cout << "MUTANTSTACK:" << std::endl;
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << "Top of MutantStack: " << mstack.top() << std::endl;

    mstack.pop();

    std::cout << "Size of MutantStack: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    mstack.push(42);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    std::cout << "Iterator after ++it: " << *it << std::endl;
    --it;
    std::cout << "Iterator after --it: " << *it << std::endl;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::stack<int> s(mstack);
    std::cout << "Top of MutantStack: " << mstack.top() << std::endl;
    std::cout << "Top of stack: " << s.top() << std::endl << std::endl;

    std::cout << "LIST:" << std::endl;
    std::list<int> l;

    l.push_back(5);
    l.push_back(17);

    std::cout << "Front of list: " << l.front() << std::endl;

    l.pop_back();

    std::cout << "Size of list: " << l.size() << std::endl;

    l.push_back(3);
    l.push_back(5);
    l.push_back(737);
    l.push_back(0);
    l.push_back(42);

    std::list<int>::iterator lit = l.begin();
    std::list<int>::iterator lite = l.end();

    ++lit;
    std::cout << "Iterator after ++it: " << *lit << std::endl;
    --lit;
    std::cout << "Iterator after --it: " << *lit << std::endl;
    while (lit != lite)
    {
        std::cout << *lit << std::endl;
        ++lit;
    }

    return (0);
}