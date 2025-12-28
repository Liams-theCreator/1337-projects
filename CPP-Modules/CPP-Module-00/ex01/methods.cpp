#include "phonebook.hpp"
#include "contact.hpp"

void Phonebook::add_in()
{
    std::string input;
    if (idx == 8)
        idx = 0;
    while (1)
    {
        std::cout << "Enter First Name: ";
        if (!std::getline(std::cin, input))
            return;
        if (contacts[idx].set_FirstName(input))
            break;
        std::cout << "Field cannot be empty !" << '\n';
    }
    
    while (1)
    {
        std::cout << "Enter Last Name: ";
        if (!std::getline(std::cin, input))
            return;
        if (contacts[idx].set_LastName(input))
            break;
        std::cout << "Field cannot be empty !" << '\n';
    }
    
    while (1)
    {
        std::cout << "Enter Nickname: ";
        if (!std::getline(std::cin, input))
            return;
        if (contacts[idx].set_NickName(input))
            break;
        std::cout << "Field cannot be empty !" << '\n';
    }
    
    while (1)
    {
        std::cout << "Enter Phone Number: ";
        if (!std::getline(std::cin, input))
            return;
        if (contacts[idx].set_PhoneNumber(input))
            break;
        std::cout << "Field cannot be empty !" << '\n';
    }
    
    while (1)
    {
        std::cout << "Enter Darkest Secret: ";
        if (!std::getline(std::cin, input))
            return;
        if (contacts[idx].set_DarkestSecret(input))
            break;
        std::cout << "Fields cannot be empty !" << '\n';
    }
    idx++;
    if (counter < 8)
        counter++;
}

std::string wide(std::string str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void Phonebook::search_in()
{
    int i = 0;
    std::string input;

    std::cout << "|  Index   |First Name|Last Name | Nickname |" << '\n';
    while (i < counter)
    {
        std::cout << "|" << std::setw(10) << i;
        std::cout << "|" << std::setw(10) << wide(contacts[i].get_FirstName());
        std::cout << "|" << std::setw(10) << wide(contacts[i].get_LastName());
        std::cout << "|" << std::setw(10) << wide(contacts[i].get_NickName());
        std::cout << "|" << '\n' ;
        i++;
    }
    std::cout << "Enter Index: ";
    std::getline(std::cin, input);
    if (input.length() == 1 && input[0] >= '0' && input[0] <= '7')
    {
        int idx = input[0] - '0';
        if (idx < counter)
        {
            std::cout << "First Name : " << contacts[idx].get_FirstName() << '\n';
            std::cout << "Last Name  : " << contacts[idx].get_LastName() << '\n';
            std::cout << "Nickname   : " << contacts[idx].get_NickName() << '\n';
            std::cout << "Phone      : " << contacts[idx].get_PhoneNumber() << '\n';
            std::cout << "Secret     : " << contacts[idx].get_DarkestSecret() << '\n';
            return;
        }
    }
    std::cout << "Enter a valid index !" << '\n';
}