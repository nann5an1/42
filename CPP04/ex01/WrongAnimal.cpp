#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal():type("Animal"){
    std::cout << "WrongAnimal Default Constructor." << std::endl;
    type = "Type: WrongAnimal";
}

WrongAnimal::~WrongAnimal(){
    std::cout << "WrongAnimal Destructor Constructor." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other){
    std::cout << "WrongAnimal Copy Constructor." << std::endl;
    *this = other;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other){
    std::cout << "WrongAnimal Assignment Operator Overload." << std::endl;
    if(this != &other)
        this->type = other.type;
    return *this;
}

void WrongAnimal::makeSound() const{
    std::cout << "Other different animal sounds." << std::endl;
}

std::string WrongAnimal:: getType() const{
    return (type);
}