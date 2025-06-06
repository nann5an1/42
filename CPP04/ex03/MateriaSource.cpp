#include "MateriaSource.hpp"

MateriaSource::MateriaSource(){}

MateriaSource:: ~MateriaSource(){}

MateriaSource::MateriaSource(const MateriaSource &other){
    *this = other;
}

MateriaSource& MateriaSource:: operator=(const MateriaSource &other){
    if(this != &other){
        for(int i = 0; i < 3; i++){
            if(!(this->_materias[i]).empty())
                this->_materias[i] = other;
        }
    }
    return (*this);
}

void MateriaSource::learnMateria(AMateria *materia){
   for (int i = 0; i < 4; ++i) {
    if (!_materias[i]) {
        _materias[i] = materia->clone();
        break;
    }
}

}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    // AMateria *materia = new AMateria(type);
    for (int i = 0; i < 4; ++i)
        if (_materias[i] && _materias[i]->getType() == type)
            return _materias[i]->clone();
    return 0;

}


