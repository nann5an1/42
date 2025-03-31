#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon{
    private:
        std::string _type;
    public:
        Weapon(std::string weaponType);
        void setType(std::string _type); //sets type
        std::string& getType(); //get the return by the ref
};

#endif