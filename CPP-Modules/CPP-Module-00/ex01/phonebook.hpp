#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <string>
#include <iostream>
#include <iomanip>
#include "contact.hpp"

class Phonebook
{
    private:
        Contact contacts[8];
        int counter;
        int idx;
    public:
        Phonebook();

        void add_in();
        void search_in();
};

#endif