#include <iostream>
#include <string>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int main(void)
{
    std::string cmd;
    PhoneBook phonebook;

    while (1)
    {
        std::cout << "Enter your command (ADD, SEARCH or EXIT):" << std::endl;
        std::getline(std::cin, cmd); // protect it
        for (int i = 0; cmd[i] != '\0'; i ++)
            cmd[i] = std::toupper(cmd[i]);
        if (cmd == "EXIT")
            return (0);
        else if (cmd == "ADD")
            phonebook.add();
        else if (cmd == "SEARCH")
            phonebook.search();
        else
            std::cout << "Invalid command :( Try again!" << std::endl;
    }
    return (0);
}