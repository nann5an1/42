#include "Zombie.hpp"

int main(){
    Zombie* horde = zombieHorde(7, "WaterZomZom");
    delete[] horde;
}