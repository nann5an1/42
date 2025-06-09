#include "MateriaSource.hpp"

MateriaSource::MateriaSource(){
    for (int i = 0; i < 4; ++i)
        _materias[i] = 0;
    // std::cout << "MateriaSource constructor" << std::endl;
}
MateriaSource:: ~MateriaSource(){
    for (int i = 0; i < 4; ++i)
    {
        if (_materias[i])
            delete _materias[i];
    }
}

MateriaSource::MateriaSource(const MateriaSource &other){
    *this = other;
}

MateriaSource& MateriaSource:: operator=(const MateriaSource &other){
    if(this != &other){
        for(int i = 0; i < 4; i++){
            if(this->_materias[i] == 0)
                this->_materias[i] = other._materias[i]->clone();
        }
    }
    return (*this);
}

void MateriaSource::learnMateria(AMateria *materia){
    for (int i = 0; i <= 4; i++) {
        if (i == 4){
            std::cout << "Materia cannot be created more than 4 items" << std::endl;
            delete materia;
            return ;
        } 
        if (!_materias[i]) {
            _materias[i] = materia;
            std::cout << "Materia " << materia->getType() << " learnt" << std::endl;
            break;
        }
}
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < 4; i++){
        if (_materias[i] && _materias[i]->getType() == type){
            std::cout << "Materia " << type << " created" << std::endl;
            return _materias[i]->clone();
        }
    }
    std::cout << "Materia " << type << " cannot be created" << std::endl;
    return 0;

}
