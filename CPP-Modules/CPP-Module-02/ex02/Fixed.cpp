#include "Fixed.hpp"

Fixed::Fixed(): fpoint_value(0)
{
    std::cout << "Default constructor called\n";  
}

Fixed::Fixed(const int num)
{
    std::cout << "Int constructor called\n";
    fpoint_value = num << fbits;
}
Fixed::Fixed(const float num)
{
    std::cout << "Float constructor called\n";
    fpoint_value = roundf(num *(1 << fbits));
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
        this->fpoint_value = other.fpoint_value;
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
float Fixed::toFloat(void) const
{
    return (float)fpoint_value / (1 << fbits);
}

int Fixed::toInt(void) const
{
    return fpoint_value >> fbits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &num)
{
    out << num.toFloat();
    return out;
}

Fixed Fixed::operator+(const Fixed &other) const 
{
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const 
{
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const 
{
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const 
{
    return Fixed(this->toFloat() / other.toFloat());
}

bool Fixed::operator>(const Fixed &other) const
{
    return fpoint_value > other.fpoint_value;
}

bool Fixed::operator<(const Fixed &other) const
{
    return fpoint_value < other.fpoint_value;
}

bool Fixed::operator>=(const Fixed &other) const
{
    return fpoint_value >= other.fpoint_value;
}

bool Fixed::operator<=(const Fixed &other) const
{
    return fpoint_value <= other.fpoint_value;
}

bool Fixed::operator==(const Fixed &other) const
{
    return fpoint_value == other.fpoint_value;
}

bool Fixed::operator!=(const Fixed &other) const
{
    return fpoint_value != other.fpoint_value;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (a < b)
        return a;
    else
        return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a < b)
        return a;
    else
        return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a > b)
        return a;
    else
        return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a > b)
        return a;
    else
        return b;
}

Fixed &Fixed::operator++()
{
    ++fpoint_value;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    ++fpoint_value;
    return temp;
}

Fixed &Fixed::operator--()
{
    --fpoint_value;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    --fpoint_value;
    return temp;
}