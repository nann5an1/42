#include "Zombie.hpp"

Zombie *newZombie( std::string name){
    Zombie *zombie = new Zombie(name); //object creation and dynamic mem allocation
    return (zombie);
}