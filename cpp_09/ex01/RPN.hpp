#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stdexcept>
#include <stack>

#define NUMBER 1
#define OPERATION 2
#define SPACE 3
#define OTHER 4

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
        static int typeOfChar(char c);
};

#endif