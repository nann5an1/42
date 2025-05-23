#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap :virtual public  ClapTrap{
    public:
        ~ScavTrap();
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(std::string name, int num);
        ScavTrap(const ScavTrap &other);
        ScavTrap& operator=(const ScavTrap &other);
        void guardGate();
        void attack(const std::string& target);
};

#endif