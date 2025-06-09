#include "AMateria.hpp"

AMateria::AMateria() : type("") {
    // std::cout << "AMateria Constructor" << std::endl;
}

AMateria::AMateria(std::string const &type){
    std::cout << "AMateria Parameterized Constructor" << std::endl;
    this->type = type;
}

AMateria::~AMateria(){
    // std::cout << "AMateria Destructor" << std::endl;
}

AMateria::AMateria(const AMateria &other){
    // std::cout << "AMateria Copy Constructor" << std::endl;
    *this = other;
}

AMateria& AMateria::operator=(const AMateria &other){
    if(this != &other)
        this->type = other.type;
    return *this;
}


std::string const &AMateria::getType() const {
    return this->type;
}

