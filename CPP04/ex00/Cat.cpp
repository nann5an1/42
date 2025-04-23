#include "Cat.hpp"

Cat::Cat():Animal(){
    std::cout << "Cat Default Constructor." << std::endl;
}


Cat::~Cat(){
    std::cout << "Cat Destructor Constructor." << std::endl;
}

Cat::Cat(const Cat &other):Animal(other){
    std::cout << "Cat Copy Constructor." << std::endl;
    *this = other;
}

Cat& Cat::operator=(const Cat &other){
    std::cout << "Cat Assignment Operator Overload." << std::endl;
    if(this != &other)
        this->type = other.type;
    return *this;
}

void Cat::makeSound(){
    std::cout << "Cat MEOWS." << std::endl;
}

std::string Cat::getType(){
    return ("Cat");
}