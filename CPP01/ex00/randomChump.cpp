#include "Zombie.hpp"
void randomChump( std::string name){
    Zombie zombie(name); //object creating and stack allocation
    zombie.announce();
}