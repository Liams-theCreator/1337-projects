#ifndef CAT_H
#define CAT_H

#include "AbsAnimal.hpp"
#include "Brain.hpp"

class Cat : public AbsAnimal
{
    private:
        Brain *brain;
    public:
        Cat();
        Cat(const Cat &other);
        Cat &operator=(const Cat &other);
        ~Cat();

        void makeSound() const;
};

#endif