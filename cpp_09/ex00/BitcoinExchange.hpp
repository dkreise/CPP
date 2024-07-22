#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <stdexcept>
#include <map>
#include <fstream>
#include <cstdlib>

class BitcoinExchange
{
    public:
        static void btc(std::string input_file);
    private:
        BitcoinExchange(void);
        BitcoinExchange(BitcoinExchange const & src);
        ~BitcoinExchange(void);
        BitcoinExchange & operator=(BitcoinExchange const & src);

        static void fillMap(std::map<std::string, float>& data);
        static void printOutput(std::string input, const std::map<std::string, float> data);
        static void validInputFormat(std::string line);
        static void validValue(float val);
        static void validDate(std::string date);
        static bool isNumber(std::string part);

};

#endif