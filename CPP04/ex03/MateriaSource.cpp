#include "MateriaSource.hpp"

MateriaSource::MateriaSource(){
    
}

MateriaSource:: ~MateriaSource(){

}

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
    *this = materia;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    // AMateria *materia = new AMateria(type);
    return (new AMateria(type));
}


