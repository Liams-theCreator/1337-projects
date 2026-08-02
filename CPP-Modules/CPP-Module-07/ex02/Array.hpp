#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>

template <typename T>
class Array
{
    private:
        T *arr;
        unsigned int _size;

    public:
        Array();
        Array(unsigned int n);
        Array(Array const &other);
        ~Array();
        Array &operator=(Array const &other);

        T &operator[](unsigned int i);
        T const &operator[](unsigned int i) const;
        unsigned int size() const;
};

template <typename T>
Array<T>::Array() : arr(0), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : arr(new T[n]()), _size(n) {}

template <typename T>
Array<T>::Array(Array const &other) : arr(new T[other._size]()), _size(other._size)
{
    for (unsigned int i = 0; i < _size; i++)
        arr[i] = other.arr[i];
}

template <typename T>
Array<T> &Array<T>::operator=(Array const &other)
{
    if (this != &other)
    {
        delete[] arr;
        _size = other._size;
        arr = new T[_size]();
        for (unsigned int i = 0; i < _size; i++)
            arr[i] = other.arr[i];
    }
    return *this;
}

template <typename T>
Array<T>::~Array()
{
    delete[] arr;
}



template <typename T>
T &Array<T>::operator[](unsigned int i)
{
    if (i >= _size)
        throw std::out_of_range("Index out of range");
    return arr[i];
}

template <typename T>
T const &Array<T>::operator[](unsigned int i) const
{
    if (i >= _size)
        throw std::out_of_range("Index out of range");
    return arr[i];
}



template <typename T>
unsigned int Array<T>::size() const
{
    return _size;
}

#endif
