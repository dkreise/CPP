#include <iostream>
#include <iomanip>
#include "Contact.hpp"

Contact::Contact(void)
{
    //std::cout << "Constructor called contact" << std::endl;
}

Contact::~Contact(void)
{
    //std::cout << "Destructor called contact" << std::endl;
}

int Contact::correct_number(std::string input)
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

std::string Contact::get_field(std::string field)
{
    std::string input;
    int correct;

    while (1)
    {
        correct = 1;
        std::cout << field << ": ";
        if (!std::getline(std::cin, input))
        {
            std::cout << "getline error :(" << std::endl;
            break;
        }
        if (input.length() == 0)
        {
            std::cout << "Empty field :( Try again!" << std::endl;
            correct = 0;
        }
        else if (field == "Phone Number")
            correct = correct_number(input);
        if (correct == 1)
            return (input);
    }
    return (input);
}

void Contact::set_new(void)
{
    this->first_name = get_field("First Name");
    this->last_name = get_field("Last Name");
    this->nickname = get_field("Nickname");
    this->phone_number = get_field("Phone Number");
    this->secret = get_field("Darkest Secret");
}

void Contact::display(void)
{
    std::cout << "First Name: " << this->first_name << std::endl;
    std::cout << "Last Name: " << this->last_name << std::endl;
    std::cout << "Nickname: " << this->nickname << std::endl;
    std::cout << "Phone Number: " << this->phone_number << std::endl;
    std::cout << "Darkest Secret: " << this->secret << std::endl;
}

void Contact::display_in_table(int ind)
{
    std::cout << std::setw(10) << ind << "|";
    if (this->first_name.length() > 10)
        std::cout << std::setw(9) << this->first_name.substr(0, 9) << "." << "|";
    else
        std::cout << std::setw(10) << this->first_name << "|";
    if (this->last_name.length() > 10)
        std::cout << std::setw(9) << this->last_name.substr(0, 9) << "." << "|";
    else
        std::cout << std::setw(10) << this->last_name << "|";
    if (this->nickname.length() > 10)
        std::cout << std::setw(9) << this->nickname.substr(0, 9) << "." << "|" << std::endl;
    else
        std::cout << std::setw(10) << this->nickname << "|" << std::endl;
}