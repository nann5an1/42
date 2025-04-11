#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(){
    FragTrap c("Juke");
    c.attack("Ben");
    c.takeDamage(3);
    c.beRepaired(1);
    c.highFivesGuys();

    ScavTrap b("Duke");
    b.attack("Ben");
    b.takeDamage(3);
    b.beRepaired(1);
    b.guardGate();
}