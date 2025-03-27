#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie{
    public:
        Zombie();
        Zombie(std::string); //constructor with params
        ~Zombie();
        void announce(void);
        void setname(std::string name);
    private:
        std::string _name;
};

Zombie* zombieHorde( int N, std::string name);

#endif