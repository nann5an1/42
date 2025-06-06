#include "Ice.hpp"

Ice:: Ice(){}
Ice:: ~Ice(){}
Ice::Ice(const Ice &other){}
Ice& Ice::operator=(const Ice &other){}

AMateria* Ice::clone() const {
    return new Ice(*this);
}
