#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main(){

    // Animal *cat = new Cat();
    // std::cout << cat->Animal::getType() << std::endl;

    std::cout << "\n\033[32mCopy Constructor test\033[0m" << std::endl;
    //copy constructor for cat
    Cat* kitty = new Cat();
    Cat* kit = new Cat(*kitty);
    kitty->makeSound();
    kit->makeSound();
    delete kitty;
    delete kit;

    std::cout << "\n\033[32mAnimal/Dog/Cat objs creation\033[0m" << std::endl;
    const Animal* animal = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << "\n\033[32mgetTypes() for all animals\033[0m" << std::endl;
    //getTypes for all animals
    std::cout << "Type: " << animal->getType() << std::endl;
    std::cout << "Type: " << dog->getType() << " " << std::endl;
    std::cout << "Type: " << cat->getType() << " " << std::endl;

    std::cout << "\n\033[32mmakeSound() for all animals\033[0m" << std::endl;
    //makeSound for all animals
    animal->makeSound();
    cat->makeSound(); //will output the cat sound!
    dog->makeSound();
    
    std::cout << "\n\033[32mWrong animal and wrong cat\033[0m" << std::endl;
    const WrongAnimal* dino = new WrongCat();
    std::cout << "Type: " << dino->getType() << std::endl;
    dino->makeSound();

    delete animal;
    delete dog;
    delete cat;
    delete dino;
    return 0;
}