#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>
#include <cstdlib>

Base* generate(void)
{
    int randval = std::rand() % 3;
    switch (randval)
    {
        case 0:
            return (new A);
        case 1:
            return (new B);
        case 3:
            return (new C);
    }
    return (NULL);
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "Actual type: A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Actual type: B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Actual type: C" << std::endl;
    else
        std::cout << "Actual type: undefined" << std::endl;
}

void identify(Base& p)
{
    try
    {
        A& a = dynamic_cast<A&>(p);
        std::cout << "Actual type: A" << std::endl;
    }
    catch(const std::bad_cast& e) {}
    try
    {
        B& b = dynamic_cast<B&>(p);
        std::cout << "Actual type: B" << std::endl;
    }
    catch(const std::bad_cast& e) {}
    try
    {
        C& c = dynamic_cast<C&>(p);
        std::cout << "Actual type: C" << std::endl;
    }
    catch(const std::bad_cast& e) {}
}

int main(void)
{
    Base* b = new B;
    Base* a = new A;
    Base* c = new C;

    identify(a);
    identify(b);

    identify(*a);
    identify(*c);

    Base* r1 = generate();
    Base* r2 = generate();
    Base* r3 = generate();

    identify(r1);
    identify(r2);
    identify(*r3);

    return (0);
}