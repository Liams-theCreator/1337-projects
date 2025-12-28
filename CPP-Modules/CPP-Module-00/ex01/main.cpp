#include "phonebook.hpp"
#include "contact.hpp"

int main(void)
{
    Phonebook note;
    std::string input;

    while (1)
    {
        std::cout << "Whats your command ? (ADD / SEARCH / EXIT)" << std::endl;
        if (!std::getline(std::cin, input))
            break;
        if (input == "ADD")
            note.add_in();
        if (input == "SEARCH")
            note.search_in();
        if (input == "EXIT")
            break;
    }
    return 0;
}