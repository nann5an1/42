#include "Cure.hpp"

Cure::Cure(){
    type = "cure";
    // std::cout << "Cure constructor" << std::endl;
}

Cure::~Cure(){
}
Cure::Cure(const Cure &other): AMateria(other){
    *this = other;
}

Cure& Cure::operator=(const Cure &other){
    if(this != &other)
        AMateria::operator=(other);
    return (*this);

}

AMateria* Cure::clone() const {
    return new Cure(*this);
}

void Cure::use(ICharacter& target){
    std::cout << "* heals " << target.getName() << " wounds *" << std::endl;
}
