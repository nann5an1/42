#include "ScavTrap.hpp"

ScavTrap::~ScavTrap(){
    std::cout << "ScavTrap destructor called." << std::endl;
}

ScavTrap::ScavTrap():ClapTrap(){
    std::cout << "ScavTrap Default constructor called." << std::endl;
}
ScavTrap::ScavTrap(std::string name):ClapTrap(name){
    std::cout << "ScavTrap Parameterized constructor called." << std::endl;
    _hit_points = 100;
    _energy_pts = 50;
    _attack_dmg = 20;
}

//inherit the copy constructor of the parent
ScavTrap::ScavTrap(const ScavTrap &other):ClapTrap(other){
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other){
    if(this != &other)
        ClapTrap::operator=(other); // Call base class assignment operator
    return (*this);
}
void ScavTrap::guardGate(){
    std::cout << "ScavTrap is now in Gatekeeper mode." << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    if (_hit_points == 0 || _energy_pts == 0)
        std::cout << "ScavTrap " << _name << " has no energy or hit points to attack!" << std::endl;
    std::cout << "ScavTrap " << _name << " throws a special punch at " << target
              << ", dealing " << _attack_dmg << " points of damage!" << std::endl;
    std::cout << "ScavTrap <" << _name << ">" << " Energy points after attack : " << _energy_pts <<  std::endl;
}
