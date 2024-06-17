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
        static void printInf(char sign);
        static void printNaN(void);
};

#endif