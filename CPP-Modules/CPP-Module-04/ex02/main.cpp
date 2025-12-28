#include "AbsAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {

    // const AbsAnimal* absAnimal = new AbsAnimal();

    const AbsAnimal* dog = new Dog();
    const AbsAnimal* cat = new Cat();

    dog->makeSound();
    cat->makeSound();

    delete dog;
    delete cat;

    return 0;
}