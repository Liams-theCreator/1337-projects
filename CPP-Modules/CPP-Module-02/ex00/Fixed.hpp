#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <string>

class Fixed
{
    private:
        int fpoint_value;
        static const int fbits = 8;
    public:
        Fixed();
        Fixed(const Fixed &Cpy);
        Fixed& operator=(const Fixed &other);
        ~Fixed();

        int getRawBits(void) const;
        void setRawBits(int const raw);
};

#endif