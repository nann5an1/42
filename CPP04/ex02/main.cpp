#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{

    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;//should not create a leak
    delete i;
    const Animal* animals[10];
    for(int i=0; i < 5; i++)
        animals[i] = new Dog();
    for(int i=5; i < 10; i++)
        animals[i] = new Cat();
    for (int i = 0; i < 10; ++i)
        delete animals[i];
    return 0;
}
