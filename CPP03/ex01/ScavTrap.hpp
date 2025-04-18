#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap :public ClapTrap{
    public:
        ~ScavTrap();
        ScavTrap();
        ScavTrap(std::string name);
        void guardGate();
        void attack(const std::string& target);
};

#endif