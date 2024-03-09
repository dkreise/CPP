#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>


class Contact
{
    public:
        Contact(void);
        ~Contact(void);
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string secret;
        std::string get_field(std::string field);
        int correct_number(std::string input);
        void set_new(void);
        void display(void);
        void display_in_table(int ind);
};

#endif