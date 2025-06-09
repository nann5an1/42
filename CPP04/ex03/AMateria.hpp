#ifndef MATERIA_A_HPP
#define MATERIA_A_HPP
#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
    protected:
        std::string type;
    public:
        AMateria();
        virtual ~AMateria();
        AMateria(const AMateria &other);
        AMateria &operator=(const AMateria &other);

        AMateria(std::string const & type);
        std::string const &getType() const;
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target) = 0;
};

#endif


