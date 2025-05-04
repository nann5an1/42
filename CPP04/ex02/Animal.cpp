#include "Animal.hpp"

Animal::Animal():type("Animal"){
    std::cout << "Animal Default Constructor." << std::endl;
    type = "Type: Animal";
}

Animal::~Animal(){
    std::cout << "Animal Destructor Constructor." << std::endl;
}

Animal::Animal(const Animal &other){
    std::cout << "Animal Copy Constructor." << std::endl;
    *this = other;
}

Animal& Animal::operator=(const Animal &other){
    std::cout << "Animal Assignment Operator Overload." << std::endl;
    if(this != &other)
        this->type = other.type;
    return *this;
}

void Animal::makeSound() const{
    std::cout << "All animals make DIFFERENT sounds." << std::endl;
}

std::string Animal:: getType() const{
    return (type);
}