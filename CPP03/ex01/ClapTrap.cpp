#include "ClapTrap.hpp"

ClapTrap::ClapTrap():_hit_points(10), _energy_pts(10), _attack_dmg(0){
    std::cout << "ClapTrap Default constructor called." << std::endl;
}
ClapTrap::~ClapTrap(){
    std::cout << "ClapTrap destructor called." << std::endl;
}

ClapTrap::ClapTrap(std::string name):_hit_points(10), _energy_pts(10), _attack_dmg(0){
    std::cout << "ClapTrap Parameterized constructor called." << std::endl;
    _name = name;
}

ClapTrap::ClapTrap(ClapTrap& other){
    *this = other;
}

ClapTrap& ClapTrap ::operator=(ClapTrap &other){
    if(this != &other){
        this->_name = other._name;
        this->_hit_points = other._hit_points;
        this->_energy_pts = other._energy_pts;
        this->_attack_dmg = other._attack_dmg;
    }
    return (*this);
}

//member functions
void ClapTrap:: attack(const std::string& target){
    if(_hit_points == 0 || _energy_pts == 0)
        std::cout << "No hit points or energy points left." << std::endl;
    _energy_pts--;
    _attack_dmg++;
    std::cout << "ClapTrap " << _name << " attacks " << target 
              << ", causing " << _attack_dmg << " points of damage!" << std::endl;
    std::cout << _name + " Energy points after attacking: " << _energy_pts << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount){
    _hit_points -= amount;
    std::cout << _name + " Hit points after damaged: " << _hit_points << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount){
    _energy_pts--;
    _hit_points = _hit_points + amount;
    std::cout << _name + " Hit points after repaired: " << _hit_points << std::endl;
    std::cout << _name + " Energy points after repaired: " << _energy_pts << std::endl;
}