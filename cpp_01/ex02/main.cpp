#include <iostream>

int main(void)
{
    std::string var = "HI THIS IS BRAIN";
    std::string* stringPTR = &var;
    std::string& stringREF = var;

    std::cout << "Memory address of the string variable: " << &var << std::endl;
    std::cout << "Memory address held by pointer: " << stringPTR << std::endl;
    std::cout << "Memory address held by reference: " << &stringREF << std::endl;

    std::cout << "Value of the string variable: " << var << std::endl;
    std::cout << "Value pointed to by pointer: " << *stringPTR << std::endl;
    std::cout << "Value pointed to by reference: " << stringREF << std::endl;

    return (0);
}