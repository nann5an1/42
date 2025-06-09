#include "Character.hpp"

Character::Character() {
    for (int i = 0; i < 4; ++i)
        _materias[i] = 0;
    std::cout << "New character created" << std::endl;
}

Character::Character(std::string name){
    for (int i = 0; i < 4; ++i)
        _materias[i] = 0;
    // std::cout << "Character Parameterized constructor" << std::endl;
    this->_name = name;
}

Character::~Character(){
    for (int i = 0; i < 4; ++i)
    {
        if (_materias[i])
            delete _materias[i];
    }
}
                 
Character::Character(const Character &other){
    *this = other;
}

Character& Character::operator=(const Character &other){
    if(this != &other){
        this->_name = other._name;
        for(int i = 0; i < 4; i++){
            if (this->_materias[i])
                delete this->_materias[i];
            this->_materias[i] = other._materias[i] ? other._materias[i]->clone() : NULL;
        }
    }
    return (*this);
}


const std::string& Character::getName() const {
    return this->_name;
}

// bool Character::hasEquipped(AMateria* m) const {
//     for (int i = 0; i < 4; ++i) {
//         if (_materias[i] == m)
//             return true;
//     }
//     return false;
// }

void Character::equip(AMateria* m){
    if (!m)
        return ;
    for(int i = 0; i < 4; i++)
    {
        // std::cout << &_materias[i] << &m << std::endl;
        if (_materias[i] == m ){
            std::cout << "Each Materia can only be equipped once" << std::endl;
            _materias[i] = NULL;
            delete m;
            return;
        }
        if(_materias[i] == NULL)
        {
            std::cout << "Materia " << m->getType() << " equipped" << std::endl;
            _materias[i] = m;
            break;
        }
    }
}

void Character::unequip(int idx){
    if (idx > 2 || idx < 0){
        std::cout << "Index out of range for unequipment" << std::endl;
        return ;
    }
    if (!_materias[idx]){
        std::cout << "Non-existent Materia" << std::endl;
        return ;
    }  
    _materias[idx] = 0;
    std::cout << "Materia unequipped at " << idx << std::endl;
}

void Character:: use(int idx, ICharacter& target){
    if (idx < 0 || idx > 3){
        std::cout << "Index out of range" << std::endl;
        return ;
    }
    if (_materias[idx])
        _materias[idx]->use(target);
    if (!_materias[idx])
        std::cout << "Materia cannot be created" << std::endl;
}