#include "ScalarConverter.hpp"

int main(int argc, char* argv[])
{
    // std::cout << INT_MAX << std::endl;
    // std::string imax = "2147483647";
    // std::string test = "21474836473";
    // std::cout << test.compare(imax) << std::endl;
    if (argc < 2)
        return (0); // print smth
    //std::cout << "***" << argv[1] << "***" << std::endl;
    ScalarConverter::convert(argv[1]); // catch exceptions?
    return (0);
}