#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & src)
{
    (void) src;
}

BitcoinExchange::~BitcoinExchange(void) {}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & src)
{
    (void) src;
    return (*this);
}

void BitcoinExchange::btc(std::string input_file)
{
    std::map<std::string, float> data;
    
    //read csv instead of this:
    data["2022-01-12"] = 43926.0f;
    data["2022-02-02"] = 36912.68f;
    data["2019-03-23"] = 4011.92f;
    data["2019-04-17"] = 5196.65f;
    //

    // for each line in input_file
    //      printOutput;
}

void BitcoinExchange::printOutput(std::string input)
{
    // check format "date | value"
    try
    {
        validInputFormat(input);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << " => " << input << std::endl;
        return;
    }
    
    // parse : str date and str value
    std::string date = input.substr(0, 10);
    std::string value = input.substr(13, input.length() - 13);

    // try validDate, validValue .. *
    // catch print error 
    // .. * (continue in try)
    // value -> to num
    // get price 
    // print "date => value = <value * price>"
    try
    {
        float val = std::atof(value.c_str());
        validDate(date);
        validValue(val);

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
}

void BitcoinExchange::validInputFormat(std::string line)
{
    if (line.length() < 14)
        throw std::logic_error("Error: bad input");
    if (line[10] == ' ' && line[11] == '|' && line[12] == ' ')
        return;
    else
        throw std::logic_error("Error: bad input");
}

void BitcoinExchange::validValue(float val)
{
    if (val < 0)
        throw std::logic_error("Error: not a positive number.");
    if (val > 1000)
        throw std::logic_error("Error: number is too large.");
}

void BitcoinExchange::validDate(std::string date)
{
    std::string year;
    std::string month;
    std::string day;

    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        throw std::logic_error("Error: not a valid date format.");
    year = date.substr(0, 4);
    month = date.substr(5, 2);
    day = date.substr(8, 2);
    if (!isNumber(year) || !isNumber(month) || !isNumber(day))
        throw std::logic_error("Error: not a valid date.");
    if (std::atoi(year.c_str()) < 2009 || std::atoi(month.c_str()) > 12 || std::atoi(day.c_str()) > 31)
        throw std::logic_error("Error: not a valid date");
}

bool BitcoinExchange::isNumber(std::string part)
{
    for (int i = 0; i < part.length(); i ++)
    {
        if (!std::isdigit(part[i]))
            return false;
    }
    return true;
}

