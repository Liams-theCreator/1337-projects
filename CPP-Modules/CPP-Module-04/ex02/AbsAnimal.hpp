#ifndef ABSANIMAL_H
#define ABSANIMAL_H

#include <iostream>
#include <string>


class AbsAnimal
{
    protected:
        std::string type;
    public:
        AbsAnimal();
        AbsAnimal(std::string type);
        AbsAnimal(const AbsAnimal &other);
        AbsAnimal &operator=(const AbsAnimal &other);
        virtual ~AbsAnimal();

        std::string getType() const;
        virtual void makeSound() const = 0;
};

#endif