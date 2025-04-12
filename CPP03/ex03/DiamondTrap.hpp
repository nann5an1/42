#ifndef DIAMOND_TRAP_HPP
#define DIAMOND_TRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap:public ScavTrap, public FragTrap{
    private:
        std::string _name;
    public:
        DiamondTrap();
        ~DiamondTrap();
        DiamondTrap(std::string _name);
        DiamondTrap(DiamondTrap const &other);
        DiamondTrap& operator=(DiamondTrap const &other);
        void whoAmI();
        using ScavTrap::attack; //use the attack from the ScavTrap class(from specific parent class)
};

#endif