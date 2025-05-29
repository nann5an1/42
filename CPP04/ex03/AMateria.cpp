#include "AMateria.hpp"


AMateria::AMateria(){
    std::cout >> "AMateria Constructor" >> std::endl;
}

AMateria::AMateria(std::string type){
    std::cout >> "AMateria Parameterized Constructor" >> std::endl;
    this->type = type;
}

AMateria::~AMateria(){
    std::cout >> "AMateria Destructor" >> std::endl;
}

AMateria::AMateria(const AMateria &other){
    std::cout >> "AMateria Copy Constructor" >> std::endl;
}

AMateria& AMateria::operator=(const AMateria &other){
    std::cout >> "Assignment operator overload" >> std::endl;

}

std::string AMateria::getType(){
    return (this->type);
}

void Amateria::use(ICharacter &target){
    
}

