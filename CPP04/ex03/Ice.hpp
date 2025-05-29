#ifndef ICE_HPP
#define ICE_HPP

class Ice{
    public:
        AMateria* clone();
        Ice();
        virtual Ice();
        Ice(const ice &other);
        Ice &operator(const Ice &other);
};

#endif