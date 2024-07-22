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
    fillMap(data);

    std::ifstream file(input_file.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: unable to open the file.");
    
    std::string line;
    while (std::getline(file, line))
    {
        printOutput(line, data);
    }
    file.close();
}

void BitcoinExchange::fillMap(std::map<std::string, float>& data)
{
    std::ifstream file("data.csv");
    if (!file.is_open())
        throw std::runtime_error("Error: unable to open the file.");

    std::string line;
    std::getline(file, line);
    while (std::getline(file, line))
    {
        std::string date = line.substr(0, 10);
        std::string value = line.substr(11, line.length() - 11);
        float val = std::atof(value.c_str());
        data[date] = val;
    }
    file.close();
}

void BitcoinExchange::printOutput(std::string input, const std::map<std::string, float> data)
{
    try
    {
        validInputFormat(input);
        std::string date = input.substr(0, 10);
        std::string value = input.substr(13, input.length() - 13);
        float val = std::atof(value.c_str());
        validDate(date);
        validValue(val);
        std::map<std::string, float>::const_iterator it = data.lower_bound(date);
        if (it != data.begin() && ((it != data.end() && it->first != date) || it == data.end()))
            it --;
        std::cout << date << " => " << val << " = " << val * it->second << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    
}

void BitcoinExchange::validInputFormat(std::string line)
{
    if (line.length() < 14)
        throw std::logic_error("Error: bad input => " + line);
    if (line[10] == ' ' && line[11] == '|' && line[12] == ' ')
        return;
    else
        throw std::logic_error("Error: bad input => " + line);
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
        throw std::logic_error("Error: not a valid date.");
}

bool BitcoinExchange::isNumber(std::string part)
{
    int len = part.length();
    for (int i = 0; i < len; i ++)
    {
        if (!std::isdigit(part[i]))
            return false;
    }
    return true;
}

