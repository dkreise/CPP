#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(ScalarConverter const & src)
{
    (void) src;
}

ScalarConverter::~ScalarConverter(void) {}

ScalarConverter & ScalarConverter::operator=(ScalarConverter const & src)
{
    (void) src;
    return (*this);
}

void ScalarConverter::convert(std::string str)
{
    try
    {
        if (str.empty())
            throw std::logic_error("Invalid argument.");
        while (str[0] == ' ')
            str.erase(0, 1);
        while (str[str.length() - 1] == ' ')
            str.erase(str.length() - 1, 1);
        if (str[0] == '\'')
            convertChar(str);
        else if (str == "-inf" || str == "-inff" || str == "+inf" || str == "+inff")
            printInf(str[0]);
        else if ((str[0] >= '0' && str[0] <= '9') || str[0] == '-' || str[0] == '+')
            convertDecimal(str);
        else if (str == "nan")
            printNaN();
        else
            throw std::logic_error("Invalid argument.");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void ScalarConverter::convertChar(std::string& str)
{
    if (str.length() != 3)
        throw std::logic_error("Invalid argument.");
    if (str[2] != '\'')
        throw std::logic_error("Invalid argument.");

    char c = str[1];
    int c_i = static_cast<int>(c);
    float c_f = static_cast<float>(c_i);
    double c_d = static_cast<double>(c_i);

    if (c_i < 32 || c_i > 126)
        std::cout << "char: non displayable" << std::endl;
    else
        std::cout << "char: \'" << c << "\'" << std::endl;
    std::cout << "int: " << c_i << std::endl;
    std::cout << "float: " << c_f << ".0f" << std::endl;
    std::cout << "double: " << c_d << ".0" << std::endl;
}

void ScalarConverter::convertDecimal(std::string& str)
{
    int i = 0;
    int len = str.length();
    int flg = 0;

    if (str[0] == '-' || str[0] == '+')
        i ++;
    if (i == len)
        throw std::logic_error("Invalid argument.");
    while (str[i] >= '0' && str[i] <= '9' && i < len)
        i ++;
    if (i == len)
    {
        printInt(str);
        return;
    }
    if (str[i] != '.')
        throw std::logic_error("Invalid argument.");
    else
        i ++;
    while (str[i] >= '0' && str[i] <= '9' && i < len)
    {
        if (str[i] != '0')
            flg = 1;
        i ++;
    }
    if (i == len)
    {
        printDouble(str, flg);
        return;
    }
    if (str[i] != 'f' || (str[i] == 'f' && i + 1 != len))
        throw std::logic_error("Invalid argument.");
    else
        printFloat(str, flg);
}

void ScalarConverter::printInt(std::string& str)
{
    double i_d = std::atof(str.c_str());
    int i = static_cast<int>(i_d);
    char i_c = static_cast<char>(i);
    float i_f = static_cast<float>(i_d);

    if (i_d < INT_MIN || i_d > INT_MAX)
        throw std::logic_error("Error: Integer Overflow.");
    if (i_d < 32 || i_d > 126)
        std::cout << "char: non displayable" << std::endl;
    else
        std::cout << "char: \'" << i_c << "\'" << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << i_f << ".0f" << std::endl;
    std::cout << "double: " << i_d << ".0" << std::endl;
}

void ScalarConverter::printFloat(std::string& str, int flg)
{
    float f = std::atof(str.c_str());
    int f_i = static_cast<int>(f);
    char f_c = static_cast<char>(f_i);
    double f_d = static_cast<double>(f);

    if (f_i < 32 || f_i > 126)
        std::cout << "char: non displayable" << std::endl;
    else
        std::cout << "char: \'" << f_c << "\'" << std::endl;
    if (f < INT_MIN || f > static_cast<float>(INT_MAX))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << f_i << std::endl;
    if ((flg == 0) && (f != std::numeric_limits<float>::infinity()) && (f != -std::numeric_limits<float>::infinity()))
    {
        std::cout << "float: " << f << ".0f" << std::endl;
        std::cout << "double: " << f_d << ".0" << std::endl;
    }
    else
    {
        std::cout << "float: " << f << "f" << std::endl;
        std::cout << "double: " << f_d << std::endl;
    }
}

void ScalarConverter::printDouble(std::string& str, int flg)
{
    double d = std::atof(str.c_str());
    int d_i = static_cast<int>(d);
    char d_c = static_cast<char>(d_i);
    float d_f = static_cast<float>(d);

    if (d_i < 32 || d_i > 126)
        std::cout << "char: non displayable" << std::endl;
    else
        std::cout << "char: \'" << d_c << "\'" << std::endl;
    if (d < INT_MIN || d > INT_MAX)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << d_i << std::endl;
    if ((flg == 0) && (d != std::numeric_limits<double>::infinity()) && (d != -std::numeric_limits<double>::infinity()))
    {
        if (d < FLT_MIN || d > FLT_MAX)
            std::cout << "float: impossible" << std::endl;
        else
            std::cout << "float: " << d_f << ".0f" << std::endl;
        std::cout << "double: " << d << ".0" << std::endl;
    }
    else
    {
        if (d < FLT_MIN || d > FLT_MAX)
            std::cout << "float: impossible" << std::endl;
        else
            std::cout << "float: " << d_f << "f" << std::endl;
        std::cout << "double: " << d << std::endl;
    }
}

void ScalarConverter::printInf(char sign)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: " << sign << "inff" << std::endl;
    std::cout << "double: " << sign << "inf" << std::endl;
}

void ScalarConverter::printNaN(void)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: nanf" << std::endl;
    std::cout << "double: nan" << std::endl;
}