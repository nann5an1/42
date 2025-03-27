#include "Zombie.hpp"

int main(){
    Zombie* zombie = newZombie("RAAH");
    zombie->announce();
    randomChump("Foo");
    delete zombie;
}