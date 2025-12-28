#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"


int main()
{
    const Animal* animals[6];
    int i = 0;

    animals[0] = new Dog();
    animals[1] = new Dog();
    animals[2] = new Dog();
    animals[3] = new Cat();
    animals[4] = new Cat();
    animals[5] = new Cat();

    for ( ; i < 6; i++)
        animals[i]->makeSound();

    i = 0;
    for ( ; i < 6; i++)
        delete animals[i];

    std::cout << "\n ---- Deep copy test ----\n";
    Dog originalDog;
    originalDog.makeSound();
    originalDog.setBrianIdea(0, "Original dog idea");
    
    Dog copiedDog;
    copiedDog = originalDog;
    copiedDog.makeSound();
    copiedDog.setBrianIdea(0, "Copied dog idea");

    std::cout << originalDog.getBrainIdea(0) << std::endl;
    std::cout << copiedDog.getBrainIdea(0) << std::endl;
    
    // Dog boby;
    // {
    //     Dog tmp = boby;
    // }
    return 0;
}