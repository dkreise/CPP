#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <stdexcept>
#include <map>
#include <fstream>

class BitcoinExchange
{
    public:
        static void btc(std::string input_file);
    private:
        BitcoinExchange(void);
        BitcoinExchange(BitcoinExchange const & src);
        ~BitcoinExchange(void);
        BitcoinExchange & operator=(BitcoinExchange const & src);

        // std::map<std::string, int> data;
        static void printOutput(std::string input);
        static void validInputFormat(std::string line);
        static void validValue(float val);
        static void validDate(std::string date);
        static bool isNumber(std::string part);

};

#endif