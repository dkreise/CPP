#include "RPN.hpp"

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cout << "Invalid number of arguments: provide one string as an argument." << std::endl;
        return (0);
    }

    try
    {
        int res = RPN::rpn(argv[1]);
        std::cout << res << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    return (0);
}