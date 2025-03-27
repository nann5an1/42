#include "Zombie.hpp"

Zombie::Zombie(std::string name){
    this->name = name;
}

Zombie::~Zombie(){
    std::cout << name << " is killed." << std::endl;
}

void Zombie::announce(void){
    std::cout << name
              << ": BraiiiiiiinnnzzzZ...\n";
}
