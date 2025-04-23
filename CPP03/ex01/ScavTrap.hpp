#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap :public ClapTrap{
    public:
        ~ScavTrap();
        ScavTrap();
        ScavTrap(const ScavTrap &other);
        ScavTrap &operator=(const ScavTrap &other);
        ScavTrap(std::string name);
        void guardGate();
        void attack(const std::string& target);
};

#endif