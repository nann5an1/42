#ifndef FRAG_TRAP_HPP
#define FRAG_TRAP_HPP

#include "ClapTrap.hpp"

//only one instance of the common base class is present. 
class FragTrap : virtual public ClapTrap{ //must set the ClapTrap to virtual so that there will only be 1 instance of ClapTrap to be called from the Diaomond
    public:
        FragTrap();
        ~FragTrap();
        FragTrap(std::string name);
        FragTrap(const FragTrap& other);
        FragTrap& operator=(const FragTrap &other);
        void highFivesGuys(void);
};

#endif
