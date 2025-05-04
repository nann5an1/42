#include "Dog.hpp"

Dog::Dog():Animal(){
    std::cout << "Dog Default Constructor." << std::endl;
    brain = new Brain();
    brain->setIdeas("Dog wants to play FETCH.");
    type = "Type: Dog";
}


Dog::~Dog(){
    std::cout << "Dog Destructor Constructor." << std::endl;
    if(brain)
        delete brain;
}


Dog::Dog(const Dog &other):Animal(other){
    std::cout << "Dog Copy Constructor." << std::endl;
    *this = other;
}

Dog& Dog::operator=(const Dog &other){
    std::cout << "Dog Assignment Operator Overload." << std::endl;
    if(this != &other)
        this->type = other.type;
    return *this;
}

void Dog::makeSound() const{
    std::cout << "Dog WOOFS." << std::endl;
}

std::string Dog::getType(){
    return type;
}