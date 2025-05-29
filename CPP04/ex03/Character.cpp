#include "Character.hpp"

Character::Character(){

}

Character::Character(std::string name){
    this->name = name;
}

Character::~Character(){

}

Character::Character(const Character &other){
    *this = other;
}

Character& Character::operator=(const Character &other){
    if(this != &other)
        return (*this);
}

void Character::equip(AMateria* m){
    //must add into the array for the incmoing materias

}

void Character::unequip(int idx){
    //check the subject
}

void Character:: use(int idx, ICharacter& target){

}