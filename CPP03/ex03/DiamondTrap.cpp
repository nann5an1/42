#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(){
    std::cout << "DiamondTrap default constructor called" << std::endl;
}
DiamondTrap::~DiamondTrap(){
    std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name):
ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name){
    std::cout << "DiamondTrap parameterized constructor called" << std::endl;
    _name = name;
    _attack_dmg = 30;
    _hit_points = FragTrap::_hit_points;
    _energy_pts = ScavTrap::_energy_pts;
    _attack_dmg = FragTrap::_attack_dmg;
}

DiamondTrap::DiamondTrap(DiamondTrap const &other) 
: ClapTrap(other), FragTrap(other), ScavTrap(other), _name(other._name){ //explicitly initialized in the copy constructor
    std::cout << "DiamondTrap copy constructor called" << std::endl;
    *this = other;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap const &other){
    std::cout << "DiamondTrap assignment operator called" << std::endl;
    if(this != &other)
        ClapTrap::operator=(other);
    return (*this);
}

void DiamondTrap::whoAmI(){
    std::cout << "Diamond Trap's name: " << _name << " & ClapTrap's : " << ClapTrap::_name << std::endl;
}

