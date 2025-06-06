#ifndef MATERIA_A_HPP
#define MATERIA_A_HPP
#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
    protected:
        std::string type;
    public:
        AMateria();
        ~AMateria();
        AMateria(const AMateria &other);
        AMateria &operator=(const AMateria &other);
        AMateria(std::string type);
        std::string const & getType() const; //Returns the materia type
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};

#endif


