#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "\n\033[32mDog/Cat/Animal Objs Creation test\033[0m" << std::endl;
    //objs created from Animal class
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    const Animal* animal = new Animal();

    std::cout << "\n\033[32mTest getType()\033[0m" << std::endl;
    std::cout << "Type: " << dog->getType() << std::endl;
    std::cout << "Type: " << cat->getType() << std::endl;
    std::cout << "Type: " << animal->getType() << std::endl;
    dog->makeSound();
    cat->makeSound();
    animal->makeSound();

    delete dog;
    delete cat;
    delete animal;

    //copy constructors
    std::cout << "\n\033[32mTest Cat Copy Constructor\033[0m" << std::endl;
    Cat* kitty = new Cat();
    Cat* kit = new Cat(*kitty);
    kit->setIdea(0, "kitty wants milk");
    std::cout << kit->getIdea(0) << std::endl;
    std::cout << kitty->getIdea(0) << std::endl;

    std::cout << "\n\033[32mTest Cat Copy Constructor\033[0m" << std::endl;
    Dog* puppy = new Dog();
    Dog* pup = new Dog(*puppy);
    pup->setIdea(1, "puppy wants milk");
    std::cout << pup->getIdea(1) << std::endl;

    std::cout << "\n\033[32mTest Destructors\033[0m" << std::endl;
    delete kitty;
    delete kit;
    delete puppy;
    delete pup;

    std::cout << "\n\033[32mCat Class Objs Creation\033[0m" << std::endl;
    //cat obj setting ideas
    const Cat* c = new Cat();
    c->setIdea(0, "Cat wants to nap");
    std::cout << c->getIdea(0) << std::endl;
    delete c;

    std::cout << "\n\033[32mDog Class Objs Creation\033[0m" << std::endl;
    //dog obj setting ideas
    const Dog* d = new Dog();
    d->setIdea(3, "Dog wants to play fetch");
    d->setIdea(4, "ruby wants to go for a walk");
    d->setIdea(4, "ruby wants to go to the park");
    std::cout << d->getIdea(2) << std::endl;
    std::cout << d->getIdea(3) << std::endl;
    std::cout << d->getIdea(4) << std::endl;
    delete d;

    //animal obj half cat, half dog
    std::cout << "\n\033[32mHalf Cat/ Half Dog Obj Creation\033[0m" << std::endl;
    const Animal* animals[6];
    for(int i = 0; i < 6; i++){
        if (i < 3)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
        std::cout << "Type: " << animals[i]->getType() << std::endl;
    }
    for (int i = 0; i < 6; ++i)
        delete animals[i];

    std::cout << "\n\033[32mBrain Class Objs Creation\033[0m" << std::endl;
    Brain* brain = new Brain();
    brain->setIdeas(4, "Cat wants to nap on lap");
    std::cout << brain->getIdeas(4)<< std::endl;
    delete brain;
    // return 0;
}
