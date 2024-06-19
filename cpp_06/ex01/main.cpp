#include "Serializer.hpp"

int main(void)
{
    Data* data;

    data = new Data;
    data->i = 42;
    data->c = 'c';

    uintptr_t dataptr = Serializer::serialize(data);
    std::cout << "The ptr of data is " << std::showbase << std::hex << dataptr << std::endl;
    Data* newdata = Serializer::deserialize(dataptr);
    std::cout << "The objects of newdata ptr:" << std::endl;
    std::cout << "newdata->i = " << std::dec << newdata->i << std::endl;
    std::cout << "newdata->c = " << newdata->c << std::endl;

    return (0);
}