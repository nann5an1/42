#include "Weapon.hpp"


Weapon::Weapon(std::string weaponType){
    _type = weaponType;
}

//adjustment here.... in the type
void Weapon::setType(std::string type){
   std::string *var = &type;
   _type = *var;
}

std::string& Weapon::getType(){
    return (_type);
}