#ifndef HUMAN_A_HPP
#define HUMAN_A_HPP

#include <iostream>


class Weapon;

class HumanA{
    private:
        std::string _name;
        std::string _type;
        Weapon &w;
    public:
        HumanA(std::string name, Weapon& w); //will always be armed
        void attack(); //displays the msg

};

#endif