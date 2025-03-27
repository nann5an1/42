#include "Zombie.hpp"

Zombie::Zombie(){}

Zombie::Zombie(std::string name){
    this->_name = name;
}

Zombie::~Zombie(){
    std::cout << _name << " is killed." << std::endl;
}

void Zombie::setname(std::string name){
    _name = name;
}

void Zombie::announce(void){
    std::cout << _name
              << ": BraiiiiiiinnnzzzZ...\n";
}
