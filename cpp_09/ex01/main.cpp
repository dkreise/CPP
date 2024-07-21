#include "RPN.hpp"

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cout << "Invalid number of arguments: provide one string of inverted Polish mathematical expression as an argument." << std::endl;
        return (0);
    }

    try
    {
        // int res = RPN::rpn(argv[1]);
        std::cout << RPN::rpn(argv[1]) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    return (0);
}