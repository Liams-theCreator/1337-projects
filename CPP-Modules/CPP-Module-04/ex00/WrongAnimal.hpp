#ifndef WANIMAL_H
#define WANIMAL_H

#include <iostream>
#include <string>


class WrongAnimal
{
    protected:
        std::string type;
    public:
        WrongAnimal();
        WrongAnimal(std::string type);
        WrongAnimal(const WrongAnimal &other);
        WrongAnimal &operator=(const WrongAnimal &other);
        ~WrongAnimal();

        std::string getType() const;
        void makeSound() const;
};

#endif