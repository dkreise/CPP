#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <stdexcept>
#include <algorithm>

template<typename T>
typename T::iterator easyfind(T& arr, int i)
{
    typename T::iterator it = std::find(arr.begin(), arr.end(), i);
    if (it == arr.end())
        throw std::logic_error("No occurance of value was found.");
    return (it);
}

#endif