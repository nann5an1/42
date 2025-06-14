#ifndef IMATERIA_SOURCE_HPP
#define IMATERIA_SOURCE_HPP
#include "AMateria.hpp"

class AMateria;

class IMateriaSource
{
public:
    virtual ~IMateriaSource() {}
    virtual void learnMateria(AMateria* m) = 0;
    virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif