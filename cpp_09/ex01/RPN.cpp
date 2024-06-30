#include "RPN.hpp"

RPN::RPN(void) {}

RPN::RPN(RPN const & src)
{
    (void) src;
}

RPN::~RPN(void) {}

RPN & RPN::operator=(RPN const & src)
{
    (void) src;
    return (*this);
}

int RPN::rpn(std::string input)
{
    std::stack<int> st;

    for (int i = 0; i < input.length(); i ++)
    {
        switch (typeOfChar(input[i]))
        {
        case NUMBER:
            st.push(input[i] - '0');
            break;
        
        case OPERATION:
            if (st.size() < 2)
            {
                std::cout << i << ": " << input[i] << " top: " << st.top() << std::endl;
                throw std::logic_error("Error: invalid input: less than 2 numbers before operation.");
            }
            doOperation(input[i], st);
            break;

        case SPACE:
            break;
        
        default:
            throw std::logic_error("Error: invalid input: invalid character.");
            break;
        }
    }

    if (st.size() != 1)
        throw std::logic_error("Error: invalid input: not unique value in the end, more operations needed.");
    
    return (st.top());
}

void RPN::doOperation(char op, std::stack<int> & st)
{
    int num1 = st.top();
    st.pop();
    int num2 = st.top();
    st.pop();
    int res = 0;
    
    switch (op)
    {
    case '+':
        res = num1 + num2;
        break;
    
    case '-':
        res = num2 - num1;
        break;

    case '*':
        res = num1 * num2;
        break;
    
    case '/':
        if (num1 == 0)
            throw std::logic_error("Error: division by zero.");
        res = num2 / num1;
        break;
    }

    st.push(res);
}

int RPN::typeOfChar(char c)
{
    if (std::isdigit(c))
        return (NUMBER);
    else if (c == '+' || c == '-' || c == '*' || c == '/')
        return (OPERATION);
    else if (c == ' ')
        return (SPACE);
    else 
        return (OTHER);
}