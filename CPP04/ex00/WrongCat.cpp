#include "WrongCat.hpp"

WrongCat::WrongCat():WrongAnimal(){
    std::cout << "WrongCat Default Constructor." << std::endl;
    type = "Type: WrongCat";
}

WrongCat::~WrongCat(){
    std::cout << "WrongCat Destructor Constructor." << std::endl;
}

WrongCat::WrongCat(const WrongCat &other):WrongAnimal(other){
    std::cout << "WrongCat Copy Constructor." << std::endl;
    *this = other;
}

WrongCat& WrongCat::operator=(const WrongCat &other){
    std::cout << "WrongCat Assignment Operator Overload." << std::endl;
    if(this != &other)
        this->type = other.type;
    return *this;
}

void WrongCat::makeSound() const{
    std::cout << "WrongCat MEOWS." << std::endl;
}

std::string WrongCat::getType() const{
    return type;
}