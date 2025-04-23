#include "ScavTrap.hpp"

ScavTrap::~ScavTrap(){
    std::cout << "ScavTrap destructor called." << std::endl;
}

ScavTrap::ScavTrap():ClapTrap(){
    std::cout << "ScavTrap Default constructor called." << std::endl;
}

ScavTrap::ScavTrap(std::string name, int num):ClapTrap(name){
    std::cout << "ScavTrap Parameterized constructor called." << std::endl;
    (void)num;
    _energy_pts = 50;
}

ScavTrap::ScavTrap(std::string name):ClapTrap(name){
    std::cout << "ScavTrap Parameterized constructor called." << std::endl;
    _hit_points = 100;
    _energy_pts = 50;
    _attack_dmg = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other):ClapTrap(other){
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other){
    if(this != &other)
        ClapTrap::operator=(other); // Call base class assignment operator
    return (*this);
}

void ScavTrap:: attack(const std::string& target){
    if(_hit_points <= 0){
        std::cout << "No hit points left." << std::endl;
        _hit_points = 0;
       return ;
    }
    if(_energy_pts <= 0){
        std::cout << "No energy points left." << std::endl;
        _energy_pts = 0;
        return ;
    }
    _energy_pts--;
    std::cout << "---" << _name << " attacks " << target << "---"<< "\n"
              << "SCAVTRAP HIT POINTS: " << _hit_points << "\n"
              << "SCAVTRAP ATTACK DAMAGE POINTS: " << _attack_dmg << "\n"
              << "SCAVTRAP ENERGY POINTS: " << _energy_pts << std::endl;
}

void ScavTrap::guardGate(){
    std::cout << "ScavTrap is now in Gatekeeper mode." << std::endl;
}