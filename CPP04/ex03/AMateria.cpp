#include "AMateria.hpp"

AMateria::AMateria() : type("") {}

AMateria::AMateria(std::string const &type){
    std::cout << "AMateria Parameterized Constructor" << std::endl;
    this->type = type;
}

AMateria::~AMateria(){}

AMateria::AMateria(const AMateria &other){
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
