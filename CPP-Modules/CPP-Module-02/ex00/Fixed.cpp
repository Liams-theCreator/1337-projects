#include "Fixed.hpp"

Fixed::Fixed(): fpoint_value(0)
{
    std::cout << "Default constructor called\n";  
}

Fixed::~Fixed()
{
    std::cout << "Destructor called\n";
}

Fixed::Fixed(const Fixed &Cpy): fpoint_value(Cpy.fpoint_value)
{
    std::cout << "Copy constructor called\n";
}
Fixed& Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called\n";
    if (this != &other)
        fpoint_value = other.fpoint_value;
    return *this;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called\n";
    return fpoint_value;
}

void Fixed::setRawBits(int const raw)
{
    fpoint_value = raw;
}
