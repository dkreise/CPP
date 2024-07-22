#include "BitcoinExchange.hpp"

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cout << "Invalid number of arguments: add an input file as an argument." << std::endl;
        return (0);
    }
    
    try
    {
        BitcoinExchange::btc(argv[1]);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    
    return (0);
}