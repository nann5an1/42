#include "FragTrap.hpp"

FragTrap::~FragTrap(){
    std::cout << "FragTrap destructor called." << std::endl;
}
FragTrap::FragTrap():ClapTrap(){
    std::cout << "FragTrap Default constructor called." << std::endl;
}
FragTrap::FragTrap(std::string name):ClapTrap(name){
    std::cout << "FragTrap Parameterized constructor called." << std::endl;
    _hit_points = 100;
    _energy_pts = 100;
    _attack_dmg = 30;
}

FragTrap::FragTrap(const FragTrap &other):ClapTrap(other){
    std::cout << "FragTrap copy constructor called" << std::endl;
}


FragTrap& FragTrap::operator=(const FragTrap &other){
    if(this != &other)
        ClapTrap::operator=(other); // Call base class assignment operator
    return (*this);
}

void FragTrap::highFivesGuys(void){
    std::cout << "FragTrap says: High five, buddy!✋😄" << std::endl;
}