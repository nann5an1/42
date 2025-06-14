#ifndef CURE_HPP
#define CURE_HPP
#include "AMateria.hpp"

class Cure : public AMateria{
    public:
        Cure();
        virtual ~Cure();
        Cure(const Cure &other);
        Cure &operator=(const Cure &other);
        AMateria* clone() const;
        virtual void use(ICharacter& target);
};

#endif