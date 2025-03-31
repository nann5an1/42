#include "HumanA.hpp"
#include "Weapon.hpp"



HumanA::HumanA(std::string name, Weapon& w){
    _name = name;
    _type = w.getType();
    std::cout << w.getType();
}

void HumanA::attack(){
    std::cout << _name << " attacks with their " << _type << std::endl;
}