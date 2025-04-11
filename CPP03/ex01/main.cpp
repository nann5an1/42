#include "ScavTrap.hpp"

int main(){
    ScavTrap b("Duke");
    b.attack("Ben");
    b.takeDamage(3);
    b.beRepaired(1);
    b.guardGate();
}