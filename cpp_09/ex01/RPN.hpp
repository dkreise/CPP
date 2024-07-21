#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stdexcept>
#include <stack>
#include <climits>

enum CHAR_TYPE
{
    NUMBER = 1,
    OPERATION,
    SPACE,
    OTHER
};


class RPN
{
    public:
        static int rpn(std::string input);
    
    private:
        RPN(void);
        RPN(RPN const & src);
        ~RPN(void);
        RPN & operator=(RPN const & src);

        static void doOperation(char op, std::stack<int> & st);
        static CHAR_TYPE typeOfChar(char c);
};

#endif