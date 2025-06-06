#ifndef CHARACTER_HPP
#define CHARACTER_HPP

class Character : public ICharacter{
    private:
        std::string _name;
        AMateria *_materias[4];
    public:
        Character();
        Character(std::string);
        ~Character();
        Character(const Character &other);
        Character &operator=(const Character &other);
        
        virtual std::string const & getName() const; // <-- ADD THIS
        virtual void equip(AMateria* m);
        virtual void unequip(int idx);
        virtual void use(int idx, ICharacter& target);
};

#endif