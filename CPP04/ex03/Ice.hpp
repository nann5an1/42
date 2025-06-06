#ifndef ICE_HPP
#define ICE_HPP

class Ice : public AMateria{
    public:
        AMateria* clone();
        Ice();
        virtual ~Ice();
        Ice(const Ice &other);
        Ice &operator=(const Ice &other);
        AMateria* clone() const;

};

#endif