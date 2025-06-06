#ifndef MATERIA_SOURCE_HPP
#define MATERIA_SOURCE_HPP
#include <string.h>

class MateriaSource: public IMateriaSource{
    protected:
        AMateria *_materias[4];
    public:
        MateriaSource();
        virtual ~MateriaSource();
        MateriaSource(const MateriaSource &other);
        MateriaSource& operator=(const MateriaSource &other);
        void learnMateria(AMateria *);
        AMateria* createMateria(std::string const & type);
};

#endif