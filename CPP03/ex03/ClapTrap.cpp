#include "ClapTrap.hpp"

ClapTrap::ClapTrap():_hit_points(10), _energy_pts(10), _attack_dmg(0){
    std::cout << "Default constructor called." << std::endl;
}
ClapTrap::~ClapTrap(){
    std::cout << "Attacker " + _name + " is destroyed." << std::endl;
}

ClapTrap::ClapTrap(std::string name):_hit_points(10), _energy_pts(10), _attack_dmg(0){
    std::cout << "Parameterized constructor called." << std::endl;
    _name = name;
}

ClapTrap::ClapTrap(const ClapTrap& other){
    *this = other;
}

ClapTrap& ClapTrap ::operator=(const ClapTrap &other){
    if(this != &other){
        this->_name = other._name;
        this->_hit_points = other._hit_points;
        this->_energy_pts = other._energy_pts;
        this->_attack_dmg = other._attack_dmg;
    }
    return (*this);
}

//member functions
void ClapTrap::attack(const std::string& target){
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
              << "CLAPTRAP HIT POINTS: " << _hit_points << "\n"
              << "CLAPTRAP ATTACK DAMAGE POINTS: " << _attack_dmg << "\n"
              << "CLAPTRAP ENERGY POINTS: " << _energy_pts << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount){
    if(_hit_points <= 0)
        std::cout << "Hit points cannot be less than or be 0. Cannot deduct from it." << std::endl;
    else{
        int temp = _hit_points - amount;
        if(temp < 0)
            _hit_points = 0;
        else
            _hit_points = temp;
        std::cout << "--- " << _name << " AFTER DAMAGED ---\n"
                    << "HIT POINTS: " << _hit_points << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount){
    // std::cout << "ENERGY POINTS CHECKPOINT -- : " << _energy_pts << std::endl;
    if(_energy_pts <= 0){
        std::cout << "Energy points must be at least 1 for repairing." << std::endl;
        return ;
    }
    else{
        _energy_pts--;
        _hit_points = _hit_points + amount;
        std::cout << "--- " + _name + " AFTER GETTING REPAIRD ---\n"
                    << "HIT POINTS: " << _hit_points << "\n"
                    << "ENERGY POINTS: " << _energy_pts << "\n";
    }
}

unsigned int ClapTrap::getHitPoints() const
{
	return _hit_points;
}