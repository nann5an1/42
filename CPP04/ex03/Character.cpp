#include "Character.hpp"

Character::Character(){}

Character::Character(std::string name){
    this->name = name;
}

Character::~Character(){}
                 
Character::Character(const Character &other){
    *this = other;
}

Character& Character::operator=(const Character &other){
    if(this != &other)
        return (*this);
}


const std::string& Character::getName() const {
    return this->_name;
}

void Character::equip(AMateria* m){
    //must add into the array for the incmoing materias
    int flag = 0;
    for(int i = 0; i < 3; i++){
        if(_materias[i] == 0){
             _materias[i] = m;
            flag = 1; 
            break;
        }
    }
    if (!flag)
        std::cout << "Inventory full." << std::endl;
}

void Character::unequip(int idx){
    //check the subject
    if (idx > 2 || idx < 0){
        std::cout << "Index out of range." << std::endl;
        return ;
    }
        
    if (!_materias[idx]){
        std::cout << "Non-existent Materia" << std::endl;
        return ;
    }  
    _materias[idx] = 0;
}

void Character:: use(int idx, ICharacter& target){
   if (_materias[idx])
        _materias[idx]->use(target);

}