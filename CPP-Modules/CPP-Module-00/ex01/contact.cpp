#include "phonebook.hpp"

bool Contact::set_FirstName(std::string FirstName)
{
    if (FirstName.empty())
        return false;
    this->FirstName = FirstName;
    return true;
}

std::string Contact::get_FirstName()
{
    return FirstName;
}

bool Contact::set_LastName(std::string LastName)
{
    if (LastName.empty())
        return false;
    this->LastName = LastName;
    return true;
}

std::string Contact::get_LastName()
{
    return LastName;
}

bool Contact::set_NickName(std::string NickName)
{
    if (NickName.empty())
        return false;
    this->NickName = NickName;
    return true;
}

std::string Contact::get_NickName()
{
    return NickName;
}

bool Contact::set_DarkestSecret(std::string DarkestSecret)
{
    if (DarkestSecret.empty())
        return false;
    this->DarkestSecret = DarkestSecret;
    return true;
}

std::string Contact::get_DarkestSecret()
{
    return DarkestSecret;
}

bool Contact::set_PhoneNumber(std::string PhoneNumber)
{
    if (PhoneNumber.empty())
        return false;
    this->PhoneNumber = PhoneNumber;
    return true;
}

std::string Contact::get_PhoneNumber()
{
    return PhoneNumber;
}