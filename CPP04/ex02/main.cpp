#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "\n\033[32mDog/Cat Class Objs Creation\033[0m" << std::endl;
    //objs created from Animal class
    // const Animal* dog = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << "\n\033[32mTest Dog/Cat getType()\033[0m" << std::endl;
    std::cout << "Type: " << dog->getType() << std::endl;
    std::cout << "Type: " << cat->getType() << std::endl;

    std::cout << "\n\033[32mTest Dog/Cat makeSound()\033[0m" << std::endl;
    cat->makeSound();
    dog->makeSound();

    delete dog;
    delete cat;

    //copy constructors
    std::cout << "\n\033[32mTest Cat Copy Constructor\033[0m" << std::endl;
    Cat* kitty = new Cat();
    Cat* kit = new Cat(*kitty);
    kit->setIdea(0, "kitty wants milk");
    std::cout << kit->getIdea(0) << std::endl;

    std::cout << "\n\033[32mTest Destructors\033[0m" << std::endl;
    std::cout << "\n\033[32mTest Cat Copy Constructor\033[0m" << std::endl;
    Dog* puppy = new Dog();
    Dog* pup = new Dog(*puppy);
    pup->setIdea(1, "puppy wants milk");
    std::cout << pup->getIdea(1) << std::endl;
    delete kitty;
    delete kit;
    delete puppy;
    delete pup;

    //cat obj setting ideas
    std::cout << "\n\033[32mCat Class Objs Creation\033[0m" << std::endl;
    const Cat* c = new Cat();
    c->setIdea(0, "Cat wants to nap");
    std::cout << c->getIdea(0) << std::endl;
    delete c;

    // //dog obj setting ideas
    std::cout << "\n\033[32mDog Class Objs Creation\033[0m" << std::endl;
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
    return 0;
}
