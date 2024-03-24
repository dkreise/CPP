#include <iostream>
#include <iomanip>
#include "Contact.hpp"

Contact::Contact(void) {}

Contact::~Contact(void) {}

int Contact::_correct_number(std::string input)
{
    for (int i = 0; input[i] != '\0'; i ++)
    {
        if (input[i] < '0' || input[i] > '9')
        {
            std::cout << "Are accepted only numbers :( Try again!" << std::endl;
            return (0);
        }
    }
    return (1);
}

std::string Contact::_get_field(std::string field)
{
    std::string input = "";
    int correct;

    while (1)
    {
        correct = 1;
        std::cout << field << ": ";
        if (!std::getline(std::cin, input))
            exit(1);
        if (input.length() == 0)
        {
            std::cout << "Empty field :( Try again!" << std::endl;
            correct = 0;
        }
        else if (field == "Phone Number")
            correct = _correct_number(input);
        if (correct == 1)
            return (input);
    }
    return (input);
}

void Contact::set_new(void)
{
    this->_first_name = _get_field("First Name");
    this->_last_name = _get_field("Last Name");
    this->_nickname = _get_field("Nickname");
    this->_phone_number = _get_field("Phone Number");
    this->_secret = _get_field("Darkest Secret");
}

void Contact::display(void)
{
    std::cout << "First Name: " << this->_first_name << std::endl;
    std::cout << "Last Name: " << this->_last_name << std::endl;
    std::cout << "Nickname: " << this->_nickname << std::endl;
    std::cout << "Phone Number: " << this->_phone_number << std::endl;
    std::cout << "Darkest Secret: " << this->_secret << std::endl;
}

void Contact::display_in_table(int ind)
{
    std::cout << std::setw(10) << ind << "|";
    if (this->_first_name.length() > 10)
        std::cout << std::setw(9) << this->_first_name.substr(0, 9) << "." << "|";
    else
        std::cout << std::setw(10) << this->_first_name << "|";
    if (this->_last_name.length() > 10)
        std::cout << std::setw(9) << this->_last_name.substr(0, 9) << "." << "|";
    else
        std::cout << std::setw(10) << this->_last_name << "|";
    if (this->_nickname.length() > 10)
        std::cout << std::setw(9) << this->_nickname.substr(0, 9) << "." << "|" << std::endl;
    else
        std::cout << std::setw(10) << this->_nickname << "|" << std::endl;
}