#include "iter.hpp"

void f_int(int& elem)
{
    elem ++;
}

void f_str(std::string& elem)
{
    elem += "_";
}

int main(void)
{
    int arr1[5] = {1, 7, 42, -3, 12345};
    std::cout << "arr1 BEFORE: ";
    std::cout << arr1[0] << ", " << arr1[1] << ", " << arr1[2] << ", " << arr1[3] << ", " << arr1[4] << ".";
    std::cout << std::endl;
    ::iter(arr1, 5, *f_int);
    std::cout << "arr1 AFTER: ";
    std::cout << arr1[0] << ", " << arr1[1] << ", " << arr1[2] << ", " << arr1[3] << ", " << arr1[4] << ".";
    std::cout << std::endl << std::endl;

    std::string arr2[3] = {"hello", "world", "!!!"};
    std::cout << "arr2 BEFORE: ";
    std::cout << arr2[0] << ", " << arr2[1] << ", " << arr2[2] << ".";
    std::cout << std::endl;
    ::iter(arr2, 3, *f_str);
    std::cout << "arr2 AFTER: ";
    std::cout << arr2[0] << ", " << arr2[1] << ", " << arr2[2] << ".";
    std::cout << std::endl;
}