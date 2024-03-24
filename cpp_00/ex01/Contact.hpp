#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact
{
    public:
        Contact(void);
        ~Contact(void);
        
        void set_new(void);
        void display(void);
        void display_in_table(int ind);
    private:
        std::string _first_name;
        std::string _last_name;
        std::string _nickname;
        std::string _phone_number;
        std::string _secret;
        
        std::string _get_field(std::string field);
        int _correct_number(std::string input);
};

#endif