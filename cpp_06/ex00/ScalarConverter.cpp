#include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string str)
{
    // do try catch
    // check if str is not empty
    while (str[0] == ' ') // maybe add \t etc
        str.erase(0, 1);
    while (str[str.length() - 1] == ' ')
        str.erase(str.length() - 1, 1);
    if (str[0] == '\'')
        convertChar(str);
        // pars_char
    else if (str == "-inf" || str == "-inff" || str == "+inf" || str == "+inff")
        printInf(str[0]);
    // else if ((str[0] >= '0' && str[0] <= '9') || str[0] == '-' || str[0] == '+')
    //     // pars dec
    else if (str == "nan")
        printNaN();
    else
        throw std::logic_error("Invalid argument.");
}

void ScalarConverter::convertChar(std::string& str)
{
    if (str.length() != 3)
        throw std::logic_error("invalid arg"); // better msg pls
    if (str[2] != '\'')
        throw std::logic_error("invalid arg");

    char c = str[1];
    int c_i = static_cast<int>(c);
    float c_f = static_cast<float>(c_i);
    double c_d = static_cast<double>(c_i);

    if (c_i < 32 || c_i > 126)
        std::cout << "char: non displayable" << std::endl;
    else
        std::cout << "char: " << c << std::endl;
    std::cout << "int: " << c_i << std::endl;
    std::cout << "float: " << c_f << ".0f" << std::endl;
    std::cout << "double: " << c_d << ".0" << std::endl;
}

// void ScalarConverter::convertDecimal(std::string& str)
// {
//     int i = 0;
//     int len = str.length();

//     if (str[0] == '-' || str[0] == '+')
// }

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