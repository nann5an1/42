#include "Ice.hpp"

Ice:: Ice() {
    type = "ice";
    // std::cout << "Ice constructor" << std::endl;
}

Ice:: ~Ice(){}

Ice::Ice(const Ice &other): AMateria(other){
    *this = other;
}

Ice& Ice::operator=(const Ice &other){
    if(this != &other){
        // delete this->clone();
        this->type = other.type;
         // AMateria::operator=(other);
    }
    return (*this);
}

AMateria* Ice::clone() const {
    return new Ice(*this);
}

void Ice:: use(ICharacter& target){
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}


