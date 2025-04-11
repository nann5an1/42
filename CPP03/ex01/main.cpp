#include "ScavTrap.hpp"

int main(){
    ScavTrap b("Duke"); //child
    b.guardGate();
    b.attack("Ben");
    b.takeDamage(3);
    b.beRepaired(1);
    
}