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
};

#endif