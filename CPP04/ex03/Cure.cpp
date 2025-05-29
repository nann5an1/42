#include "Cure.hpp"

Cure::Cure(){

}
Cure::~Cure(){

}

Cure::Cure(const Cure &other){

}

Cure& Cure::operator=(const Cure &other){

}

AMateria* Cure::clone()
{
    return (new Cure(*this));
}

