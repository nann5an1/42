#include "DiamondTrap.hpp"


// ClapTrap::name (parameter of the constructor + "_clap_name" suffix)
// • Hit points (FragTrap)
// • Energy points (ScavTrap)
// • Attack damage (FragTrap)
// • attack() (ScavTrap)

int main(){
    DiamondTrap c("Rex");
    // c.whoAmI();
    c.attack("Ben");  
    c.highFivesGuys();
    c.takeDamage(10);  //energy points have to inherits that of the ScavTrap, which is 50
    c.beRepaired(2);
    // c.guardGate();
}