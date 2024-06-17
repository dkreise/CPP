#include "ScalarConverter.hpp"

int main(int argc, char* argv[])
{
    if (argc < 2)
        return (1); // print smth
    //std::cout << "***" << argv[1] << "***" << std::endl;
    ScalarConverter::convert(argv[1]); // catch exceptions?
    return (0);
}