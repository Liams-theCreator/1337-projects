#ifndef HARL_H
#define HARL_H

#include <iostream>
#include <string>

#define H_DEBUG 0
#define H_INFO 1
#define H_WARNING 2
#define H_ERROR 3

class Harl
{
    private:
        void debug();
        void info();
        void warning();
        void error();
    public:
        Harl();
        ~Harl();
        void complain(std::string level);
};

#endif