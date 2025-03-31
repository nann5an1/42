#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP

#include <iostream>

class Weapon;

class HumanB{
    public:
        HumanB(std::string name); // will not always have weapon
        void setWeapon(Weapon w);
        void setType(std::string type);
        void attack();

};

#endif