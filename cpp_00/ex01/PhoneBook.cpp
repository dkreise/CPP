#include <iostream>
#include <iomanip>
#include "Contact.hpp"
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
    _cur_ind= 0;
    _cnt = 0;
}

PhoneBook::~PhoneBook(void) {}

void PhoneBook::add(void)
{
    if (_cur_ind == 8)
        _cur_ind = 0;
    _contacts[_cur_ind].set_new();
    _cur_ind ++;
    if (_cnt < 8)
        _cnt ++;
}

void PhoneBook::_display_all(void)
{
    std::cout << std::setw(10) << "Index" << "|";
    std::cout << std::setw(10) << "First Name" << "|";
    std::cout << std::setw(10) << "Last Name" << "|";
    std::cout << std::setw(10) << "Nickname" << "|" << std::endl;
    for (int i = 0; i < _cnt; i ++)
        _contacts[i].display_in_table(i + 1);
}

void PhoneBook::search(void)
{
    std::string s_ind;
    int ind;

    this->_display_all();
    while (1)
    {   
        std::cout << "Enter the index of the contact for more information: ";
        if (!std::getline(std::cin, s_ind))
            exit(1);
        if (s_ind.length() == 0)
            return ;
        if (s_ind.length() != 1 || (s_ind[0] < '1' || s_ind[0] > '9'))
            std::cout << "Invalid input :( Try again!" << std::endl;
        else
        {   
            ind = s_ind[0] - '0' - 1;
            if (ind < _cur_ind)
            {
                _contacts[ind].display();
                return ;
            }
            else
                std::cout << "Contact does not exist :( Try again!" << std::endl;
        }
    }
}