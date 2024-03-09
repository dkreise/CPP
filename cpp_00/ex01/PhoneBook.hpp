#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include "Contact.hpp"

class PhoneBook
{
    public:
        PhoneBook(void);
        ~PhoneBook(void);
        Contact contacts[8];
        void add(void);
        void search(void);
    private:
        int _cur_ind;
        int _cnt;
        void _display_all(void);
};

#endif