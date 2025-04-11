#ifndef FRAG_TRAP_HPP
#define FRAP_TRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap{
    public:
        FragTrap();
        ~FragTrap();
        FragTrap(std::string name);
        FragTrap(const FragTrap& other);
        FragTrap& operator=(const FragTrap &other);
        void highFivesGuys(void);
};

#endif
