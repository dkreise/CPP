#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>
#include <stdexcept>

class ScalarConverter
{
    public:
        static void convert(std::string str);
        
    private:
        ScalarConverter(void);
        ~ScalarConverter(void);

        static void convertChar(std::string& str);
        static void convertDecimal(std::string& str);
        static void printInt(std::string& str);
        static void printFloat(std::string& str, int flg);
        static void printDouble(std::string& str, int flg);
        static void printInf(char sign);
        static void printNaN(void);
};

#endif