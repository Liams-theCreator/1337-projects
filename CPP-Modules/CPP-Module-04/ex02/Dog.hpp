#ifndef DOG_H
#define DOG_H

#include "AbsAnimal.hpp"
#include "Brain.hpp"

class Dog : public AbsAnimal
{
    private:
        Brain *brain;
    public:
        Dog();
        Dog(const Dog &other);
        Dog &operator=(const Dog &other);
        ~Dog();

        void makeSound() const;
};


#endif