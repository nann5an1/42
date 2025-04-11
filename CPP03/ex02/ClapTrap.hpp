#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>

class ClapTrap{
    protected:
        std::string _name;
        unsigned int _hit_points;
        unsigned int _energy_pts;
        unsigned int _attack_dmg;
    public:
        ClapTrap();
        ~ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(ClapTrap& other);
        ClapTrap& operator=(ClapTrap &other);

        //member functions
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif