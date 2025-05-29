#ifndef CHARACTER_HPP
#define CHARACTER_HPP

class Character : public ICharacter{
    private:
        AMateria *_materias[4];
    public:
        Character();
        Character(std::string);
        ~Character();
        Character(const Character &other);
        Character &operator=(const Character &other);
        virtual void equip(AMateria* m) override;
        virtual void unequip(int idx) override;
        virtual void use(int idx, ICharacter& target) override;
}

#endif